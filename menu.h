#ifndef MENU_H
#define MENU_H

#ifdef HAVE_NCURSES_H
# include <ncurses.h>
#elif HAVE_CURSES_H
# include <curses.h>
#endif

#include "files.h"

enum menu_request
{
	REQ_UP,
	REQ_DOWN,
	REQ_PGUP,
	REQ_PGDOWN,
	REQ_TOP,
	REQ_BOTTOM
};

enum menu_align
{
	MENU_ALIGN_RIGHT,
	MENU_ALIGN_LEFT
};

struct menu_item
{
	char *title;		/* Titile of the item */
	enum menu_align align;	/* Align of the title */
	int num;		/* Position of the item starting from 0. */

	/* Curses attributes in different states: */
	int attr_normal;
	int attr_sel;
	int attr_marked;
	int attr_sel_marked;
	
	/* Associated file: */
	char *file;
	enum file_type type;

	/* Additional information shown: */
	char time[6];		/* File time string */
	char format[4];		/* File format */

	struct menu_item *next;
	struct menu_item *prev;
};

struct menu
{
	WINDOW *win;
	struct menu_item *items;
	int nitems;		/* number of present items */
	struct menu_item *top;	/* first visible item */
	struct menu_item *last;	/* last item in the menu */

	/* position and size */
	int posx;
	int posy;
	int width;
	int height;
	
	struct menu_item *selected;	/* selected item */
	struct menu_item *marked;	/* index of the marked item or -1 */

	/* Flags for displaying information about the file. */
	int show_time;
	int show_format;

	int info_attr;	/* attributes for information about the file */
	int number_items; /* display item number (position) */
};

/* Menu state: relative (to the first item) positions of the top and selected
 * items. */
struct menu_state
{
	int top_item;
	int selected_item;
};

struct menu *menu_new (WINDOW *win, const int posx, const int posy,
		const int width, const int height);
struct menu_item *menu_add (struct menu *menu, const char *title,
		const enum file_type type, const char *file);

void menu_item_set_attr_normal (struct menu_item *mi, const int attr);
void menu_item_set_attr_sel (struct menu_item *mi, const int attr);
void menu_item_set_attr_sel_marked (struct menu_item *mi, const int attr);
void menu_item_set_attr_marked (struct menu_item *mi, const int attr);

void menu_item_set_time (struct menu_item *mi, const char *time);
void menu_item_set_format (struct menu_item *mi, const char *format);

void menu_free (struct menu *menu);
void menu_driver (struct menu *menu, const enum menu_request req);
void menu_setcurritem_title (struct menu *menu, const char *title);
void menu_setcurritem_file (struct menu *menu, const char *file);
void menu_draw (const struct menu *menu, const int active);
void menu_mark_item (struct menu *menu, const char *file);
void menu_set_state (struct menu *menu, const struct menu_state *st);
void menu_get_state (const struct menu *menu, struct menu_state *st);
void menu_update_size (struct menu *menu, const int posx, const int posy,
		const int width, const int height);
void menu_unmark_item (struct menu *menu);
struct menu *menu_filter_pattern (const struct menu *menu, const char *pattern);
void menu_set_show_time (struct menu *menu, const int t);
void menu_set_show_format (struct menu *menu, const int t);
void menu_set_info_attr (struct menu *menu, const int attr);
void menu_set_items_numbering (struct menu *menu, const int number);
enum file_type menu_item_get_type (const struct menu_item *mi);
char *menu_item_get_file (const struct menu_item *mi);
struct menu_item *menu_curritem (struct menu *menu);
void menu_item_set_title (struct menu_item *mi, const char *title);
int menu_nitems (const struct menu *menu);
struct menu_item *menu_find (struct menu *menu, const char *fname);
void menu_del_item (struct menu *menu, const char *fname);
void menu_item_set_align (struct menu_item *mi, const enum menu_align align);

#endif
