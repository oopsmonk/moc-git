#ifndef PLAYER_H
#define PLAYER_H

#include "file_types.h"
#include "buf.h"

void player_cleanup ();
void player (const char *file, struct decoder_funcs *f, struct buf *out_buf);
void player_stop ();
void player_seek (const int n);
void player_reset ();

#endif
