
#ifndef INTERFACE_H
#define INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

/* The desired state of the client (and server). */
enum want_quit {
	NO_QUIT,	/* don't want to quit */
	QUIT_CLIENT,	/* only quit the client */
	QUIT_SERVER	/* quit the client and the server */
};

/* Information about the currently played file. */
struct file_tags;
struct file_info {
	char *file;
	struct file_tags *tags;
	char *title;
	int avg_bitrate;
	int bitrate;
	int rate;
	int curr_time;
	int total_time;
	int channels;
	int state; /* STATE_* */
	char *block_file;
	int block_start;
	int block_end;
};

struct lists_s_strs;

void init_interface (const int sock, const int logging, struct lists_s_strs *args);
void interface_loop ();
void interface_end ();
int user_wants_interrupt ();
void interface_error (const char *msg);

#ifdef HAVE_ATTRIBUTE__
void interface_fatal (const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
#else
void interface_fatal (const char *format, ...);
#endif

void interface_cmdline_clear_plist (int server_sock);
void interface_cmdline_append (int server_sock, struct lists_s_strs *args);
void interface_cmdline_play_first (int server_sock);
void interface_cmdline_file_info (const int server_sock);
void interface_cmdline_playit (int server_sock, struct lists_s_strs *args);
void interface_cmdline_seek_by (int server_sock, const int seek_by);
void interface_cmdline_jump_to_percent (int server_sock, const int percent);
void interface_cmdline_jump_to (int server_sock, const int pos);
void interface_cmdline_adj_volume (int server_sock, const char *arg);
void interface_cmdline_set (int server_sock, char *arg, const int val);
void interface_cmdline_formatted_info (const int server_sock, const char *format_str);
void interface_cmdline_enqueue (int server_sock, struct lists_s_strs *args);
void interface_cmdline_play_num (int server_sock, const char *file);

#ifdef __cplusplus
}
#endif

#endif
