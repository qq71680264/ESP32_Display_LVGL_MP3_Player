#include <lvgl.h>
#include <TFT_eSPI.h>
#include "events_init.h"
#include "gui_guider.h"
#include "custom.h"
#include <Arduino.h>

#define mp3 Serial2

static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[480 * 320 / 13];
lv_ui guider_ui;

void SelectPlayerDevice(uint8_t device);
void SetVolume(uint8_t volume);
void PlayPause(void);
void PlayResume(void);
void PlayNext(void);
void PlayPrevious(void);

TFT_eSPI lcd = TFT_eSPI(); 

uint16_t calData[5] = { 353, 3568, 269, 3491, 7  };

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  lcd.startWrite();
  lcd.setAddrWindow( area->x1, area->y1, w, h );
  lcd.pushColors( ( uint16_t * )&color_p->full, w * h, true );
  lcd.endWrite();

  lv_disp_flush_ready( disp );
}

uint16_t touchX, touchY;

void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{

  bool touched = lcd.getTouch( &touchX, &touchY, 600);
  if ( !touched )
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;


    data->point.x = touchX;
    data->point.y = touchY;

    Serial.print( "Data x " );
    Serial.println( touchX );

    Serial.print( "Data y " );
    Serial.println( touchY );
  }
}

void setup()
{
  mp3.begin(9600); 
  SelectPlayerDevice(0x02);       // Select SD card as the player device.
  SetVolume(0x1E);                // Set the volume, the range is 0x00 to 0x1E(0 - 30).
  
  lv_init();

  lcd.begin();
  lcd.setRotation(1);
  lcd.fillScreen(TFT_BLACK);
  delay(100);
 
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH); 

  lcd.setTouch(calData);


  lv_disp_draw_buf_init( &draw_buf, buf1, NULL, screenWidth * screenHeight / 13 );

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );

  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );

  setup_ui(&guider_ui);
  events_init(&guider_ui);
  custom_init(&guider_ui);
}

void loop()
{
  while(1)
  {
    lv_task_handler();
    delay(5);
  }
}

/**************************************************************** 
 * Function Name: PlayPause
 * Description: Pause the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayPause(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x0E);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
//  mp3.write(0xFE);
//  mp3.write(0xED);
    mp3.write(0xEF);
    delay(20);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayResume
 * Description: Resume the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayResume(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x0D);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
//  mp3.write(0xFE);
//  mp3.write(0xEE);
    mp3.write(0xEF);
    delay(20);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayNext
 * Description: Play the next song.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayNext(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x01);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayPrevious
 * Description: Play the previous song.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayPrevious(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x02);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/**************************************************************** 
 * Function Name: SpecifyMusicPlay
 * Description: Specify the music index to play, the index is decided by the input sequence of the music.
 * Parameters: index: the music index: 0-65535.
 * Return: none
****************************************************************/ 
void SpecifyMusicPlay(uint16_t index)
{
    uint8_t hbyte, lbyte;
    hbyte = index / 256;
    lbyte = index % 256;
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x03);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(hbyte));
    mp3.write(uint8_t(lbyte));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/**************************************************************** 
 * Function Name: SelectPlayerDevice
 * Description: Select the player device, U DISK or SD card.
 * Parameters: 0x01:U DISK;  0x02:SD card
 * Return: none
****************************************************************/ 
void SelectPlayerDevice(uint8_t device)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x09);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(device);
    mp3.write(0xEF);
    delay(200);
}

/**************************************************************** 
 * Function Name: SetVolume
 * Description: Set the volume, the range is 0x00 to 0x1E.
 * Parameters: volume: the range is 0x00 to 0x1E.
 * Return: none
****************************************************************/ 
void SetVolume(uint8_t volume)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x06);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(volume);
    mp3.write(0xEF);
    delay(10);
//  return true;
}
