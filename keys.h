#ifndef KEYS_H
#define KEYS_H

enum key_cmd
{
	KEY_CMD_QUIT_CLIENT,
	KEY_CMD_GO,
	KEY_CMD_MENU_DOWN,
	KEY_CMD_MENU_UP,
	KEY_CMD_MENU_NPAGE,
	KEY_CMD_MENU_PPAGE,
	KEY_CMD_MENU_FIRST,
	KEY_CMD_MENU_LAST,
	KEY_CMD_QUIT,
	KEY_CMD_STOP,
	KEY_CMD_NEXT,
	KEY_CMD_PREVIOUS,
	KEY_CMD_PAUSE,
	KEY_CMD_TOGGLE_READ_TAGS,
	KEY_CMD_TOGGLE_REPEAT,
	KEY_CMD_TOGGLE_AUTO_NEXT,
	KEY_CMD_TOGGLE_PLAYLIST,
	KEY_CMD_PLIST_ADD_FILE,
	KEY_CMD_PLIST_CLEAR,
	KEY_CMD_PLIST_ADD_DIR,
	KEY_CMD_MIXED_DEC_1,
	KEY_CMD_MIXER_INC_1,
	KEY_CMD_MIXER_DEC_5,
	KEY_CMD_MIXER_INC_5,
	KEY_CMD_SEEK_FORWARD_1,
	KEY_CMD_SEEK_BACKWARD_1,
	KEY_CMD_HELP,
	KEY_CMD_HIDE_MESSAGE,
	KEY_CMD_REFRESH,
	KEY_CMD_RELOAD,
	KEY_CMD_TOGGLE_SHOW_HIDDEN_FILES,
	KEY_CMD_GO_MUSIC_DIR,
	KEY_CMD_PLIST_DEL,
	KEY_CMD_MENU_SEARCH,
	KEY_CMD_PLIST_SAVE,
	KEY_CMD_TOGGLE_SHOW_FORMAT,
	KEY_CMD_TOGGLE_SHOW_TIME,
	KEY_CMD_GO_TO_PLAYING_FILE,
	KEY_CMD_GO_DIR,
	KEY_CMD_GO_DIR_UP,
	KEY_CMD_TOGGLE_SHUFFLE,
	KEY_CMD_NEXT_SEARCH,
	KEY_CMD_CANCEL,
	KEY_CMD_WRONG
};

/* Key context is the place where the user presses a key. A key can have
 * different meanings in diffrent places. */
enum key_context
{
	CON_MENU,
	CON_ENTRY_SEARCH,
	CON_ENTRY
};

#ifndef KEY_ESCAPE
# define KEY_ESCAPE	27
#endif

#define META_KEY_FLAG	0x80

enum key_cmd get_key_cmd (const enum key_context context, const int key);
void keys_init ();
void keys_cleanup ();
char **get_keys_help (int *num);

#endif
