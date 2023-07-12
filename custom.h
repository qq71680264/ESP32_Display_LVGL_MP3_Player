// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "MP3Player_KT403A.h"
#include "gui_guider.h"

void custom_init(lv_ui *ui);
void tracks_up(void);
void tracks_down(void);
bool tracks_is_up(void);
void lv_demo_music_resume(void);
void lv_demo_music_pause(void);
void lv_demo_music_album_next(bool next);
void lv_demo_music_play(uint32_t id);
void lv_demo_music_list_btn_check(uint32_t track_id, bool state);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
