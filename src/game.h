/**
 * @file game.h
 *
 * Header file for game management
 *
 * @date 1998 - 2024
 * @author Richard Delorme
 * @author Toshihiko Okuhara
 * @version 4.6
 */

#ifndef EDAX_GAME_H
#define EDAX_GAME_H

#include "board.h"
#include "move.h"

#include <stdio.h>

/* structures */
struct Random;

typedef struct Game {
	Board initial_board;
	struct {
		int16_t year;
		int8_t month;
		int8_t day;
		int8_t hour;
		int8_t minute;
		int8_t second;
	} date;
	char name[2][32];
	uint8_t move[60];
	uint8_t player;
	uint64_t hash;
} Game;

typedef struct WthorGame {
	short tournament, black, white;
	int8_t score, theoric_score;
	char x[60];
} WthorGame;

typedef struct OkoGame {
	char n;
	int8_t score;
	char flag;
	char move[61];
} OkoGame;

/* function declarations */
void game_init(Game*);
void game_copy(Game*, const Game*);
bool game_get_board(const Game*, const int, Board*);
bool game_update_board(Board *board, int x);
bool game_check(Game*);
bool game_equals(const Game*, const Game*);
void wthor_to_game(const WthorGame*, Game*);
void game_to_wthor(const Game*, WthorGame*);
void game_read(Game*, FILE*);
void game_write(const Game*, FILE*);
void game_import_text(Game*, FILE*);
void game_import_wthor(Game*, FILE*);
void game_import_ggf(Game*, FILE*);
void game_import_sgf(Game*, FILE *);
char* parse_ggf(Game*, const char*, bool*);
void game_import_pgn(Game*, FILE *);
void game_export_text(const Game*, FILE*);
void game_export_ggf(const Game*, FILE*);
void game_save_sgf(const Game*, FILE *, const bool);
void game_export_sgf(const Game*, FILE *);
void game_export_pgn(const Game*, FILE *);
void game_export_wthor(const Game*, FILE*);
void game_export_eps(const Game*, FILE *);
void game_export_svg(const Game*, FILE *);
void game_import_oko(Game*, FILE*);
void game_import_gam(Game*, FILE *);
void game_rand(Game*, int, struct Random*);
int game_analyze(Game*, struct Search*, const int, const bool);
int game_complete(Game*, struct Search*);
void line_to_game(const Board*, const Line*, Game*);
int game_score(const Game*);
int move_from_wthor(int);

#endif /* EDAX_GAME_H */
