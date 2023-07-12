/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_11;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_label_time_8;
	lv_obj_t *screen_label_time_7;
	lv_obj_t *screen_label_time_6;
	lv_obj_t *screen_label_time_5;
	lv_obj_t *screen_label_time_4;
	lv_obj_t *screen_label_time_3;
	lv_obj_t *screen_label_time_2;
	lv_obj_t *screen_label_time_1;
	lv_obj_t *screen_label_author_8;
	lv_obj_t *screen_label_author_7;
	lv_obj_t *screen_label_author_6;
	lv_obj_t *screen_label_author_5;
	lv_obj_t *screen_label_author_4;
	lv_obj_t *screen_label_author_3;
	lv_obj_t *screen_label_author_2;
	lv_obj_t *screen_label_music_8;
	lv_obj_t *screen_label_music_7;
	lv_obj_t *screen_label_music_6;
	lv_obj_t *screen_label_music_5;
	lv_obj_t *screen_label_music_4;
	lv_obj_t *screen_label_music_3;
	lv_obj_t *screen_label_music_2;
	lv_obj_t *screen_img_8;
	lv_obj_t *screen_img_7;
	lv_obj_t *screen_img_6;
	lv_obj_t *screen_img_5;
	lv_obj_t *screen_img_4;
	lv_obj_t *screen_img_3;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_label_author_1;
	lv_obj_t *screen_label_music_1;
	lv_obj_t *screen_btn_8;
	lv_obj_t *screen_btn_8_label;
	lv_obj_t *screen_btn_7;
	lv_obj_t *screen_btn_7_label;
	lv_obj_t *screen_btn_6;
	lv_obj_t *screen_btn_6_label;
	lv_obj_t *screen_btn_5;
	lv_obj_t *screen_btn_5_label;
	lv_obj_t *screen_btn_4;
	lv_obj_t *screen_btn_4_label;
	lv_obj_t *screen_btn_3;
	lv_obj_t *screen_btn_3_label;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_player;
	lv_obj_t *screen_img_album;
	lv_obj_t *screen_imgbtn_play;
	lv_obj_t *screen_imgbtn_play_label;
	lv_obj_t *screen_img_9;
	lv_obj_t *screen_img_10;
	lv_obj_t *screen_img_wave_bottom;
	lv_obj_t *screen_img_wave_top;
	lv_obj_t *screen_img_icn_rnd;
	lv_obj_t *screen_img_icn_loop;
	lv_obj_t *screen_img_icn_left;
	lv_obj_t *screen_img_icn_right;
	lv_obj_t *screen_slider_1;
	lv_obj_t *screen_img_icn_msg;
	lv_obj_t *screen_img_icn_heart;
	lv_obj_t *screen_img_icn_donwload;
	lv_obj_t *screen_img_icn_chart;
	lv_obj_t *screen_label_slider_time;
	lv_obj_t *screen_label_tracks;
	lv_obj_t *screen_btn_tracks;
	lv_obj_t *screen_btn_tracks_label;
	lv_obj_t *screen_label_title_music;
	lv_obj_t *screen_label_title_author;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_btn_list_pause_42x42);
LV_IMG_DECLARE(_cover_1_105x105);
LV_IMG_DECLARE(_btn_play_alpha_48x56);
LV_IMG_DECLARE(_cover_2_105x105);
LV_IMG_DECLARE(_wave_bottom_480x34);
LV_IMG_DECLARE(_cover_3_105x105);
LV_IMG_DECLARE(_icn_slider_15x15);
LV_IMG_DECLARE(_wave_top_480x34);
LV_IMG_DECLARE(_btn_loop_15x15);
LV_IMG_DECLARE(_btn_pause_alpha_48x56);
LV_IMG_DECLARE(_btn_rnd_15x15);
LV_IMG_DECLARE(_btn_prev_37x37);
LV_IMG_DECLARE(_btn_list_play_42x42);
LV_IMG_DECLARE(_btn_next_37x37);
LV_IMG_DECLARE(_icn_chart_15x15);
LV_IMG_DECLARE(_icn_heart_15x15);
LV_IMG_DECLARE(_icn_download_15x15);
LV_IMG_DECLARE(_icn_chat_15x15);

#ifdef __cplusplus
}
#endif
#endif