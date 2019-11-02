#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
#include "assets/default/inc/strings/en_US.data"
#include "assets/default/inc/strings/zh_CN.data"
#include "assets/default/inc/styles/default.data"
#include "assets/default/inc/styles/dialog.data"
#include "assets/default/inc/styles/dialog_confirm.data"
#include "assets/default/inc/styles/dialog_info.data"
#include "assets/default/inc/styles/dialog_toast.data"
#include "assets/default/inc/styles/dialog_warn.data"
#include "assets/default/inc/styles/keyboard.data"
#include "assets/default/inc/styles/main.data"
#include "assets/default/inc/styles/window1.data"
#include "assets/default/inc/ui/books.data"
#include "assets/default/inc/ui/calculator.data"
#include "assets/default/inc/ui/custom_handlers.data"
#include "assets/default/inc/ui/demo9_main.data"
#include "assets/default/inc/ui/home.data"
#include "assets/default/inc/ui/humidity.data"
#include "assets/default/inc/ui/js_address.data"
#include "assets/default/inc/ui/js_books.data"
#include "assets/default/inc/ui/js_calculator.data"
#include "assets/default/inc/ui/js_com_settings.data"
#include "assets/default/inc/ui/js_demo9_main.data"
#include "assets/default/inc/ui/js_home.data"
#include "assets/default/inc/ui/js_humidity.data"
#include "assets/default/inc/ui/js_room_settings.data"
#include "assets/default/inc/ui/js_shape.data"
#include "assets/default/inc/ui/js_temperature1.data"
#include "assets/default/inc/ui/js_temperature10.data"
#include "assets/default/inc/ui/js_temperature14.data"
#include "assets/default/inc/ui/js_temperature17.data"
#include "assets/default/inc/ui/js_temperature18.data"
#include "assets/default/inc/ui/js_temperature2.data"
#include "assets/default/inc/ui/js_temperature3.data"
#include "assets/default/inc/ui/js_temperature4.data"
#include "assets/default/inc/ui/js_temperature5.data"
#include "assets/default/inc/ui/js_temperature6.data"
#include "assets/default/inc/ui/js_temperature9.data"
#include "assets/default/inc/ui/js_temperature_humidity.data"
#include "assets/default/inc/ui/kb_ascii.data"
#include "assets/default/inc/ui/kb_default.data"
#include "assets/default/inc/ui/kb_float.data"
#include "assets/default/inc/ui/kb_hex.data"
#include "assets/default/inc/ui/kb_int.data"
#include "assets/default/inc/ui/kb_phone.data"
#include "assets/default/inc/ui/kb_ufloat.data"
#include "assets/default/inc/ui/kb_uint.data"
#include "assets/default/inc/ui/room_settings.data"
#include "assets/default/inc/ui/shape.data"
#include "assets/default/inc/ui/temperature1.data"
#include "assets/default/inc/ui/temperature10.data"
#include "assets/default/inc/ui/temperature14.data"
#include "assets/default/inc/ui/temperature16.data"
#include "assets/default/inc/ui/temperature17.data"
#include "assets/default/inc/ui/temperature2.data"
#include "assets/default/inc/ui/temperature3.data"
#include "assets/default/inc/ui/temperature4.data"
#include "assets/default/inc/ui/temperature5.data"
#include "assets/default/inc/ui/temperature6.data"
#include "assets/default/inc/ui/temperature9.data"
#include "assets/default/inc/ui/temperature_humidity.data"
#ifdef WITH_STB_IMAGE
#include "assets/default/inc/images/1.res"
#include "assets/default/inc/images/2.res"
#include "assets/default/inc/images/3.res"
#include "assets/default/inc/images/active_dot.res"
#include "assets/default/inc/images/ani1.res"
#include "assets/default/inc/images/ani2.res"
#include "assets/default/inc/images/ani3.res"
#include "assets/default/inc/images/ani4.res"
#include "assets/default/inc/images/ani5.res"
#include "assets/default/inc/images/ani6.res"
#include "assets/default/inc/images/ani7.res"
#include "assets/default/inc/images/ani8.res"
#include "assets/default/inc/images/ani9.res"
#include "assets/default/inc/images/ania.res"
#include "assets/default/inc/images/anib.res"
#include "assets/default/inc/images/anic.res"
#include "assets/default/inc/images/arrow_down_n.res"
#include "assets/default/inc/images/arrow_down_o.res"
#include "assets/default/inc/images/arrow_down_p.res"
#include "assets/default/inc/images/arrow_left_n.res"
#include "assets/default/inc/images/arrow_left_o.res"
#include "assets/default/inc/images/arrow_left_p.res"
#include "assets/default/inc/images/arrow_right_n.res"
#include "assets/default/inc/images/arrow_right_o.res"
#include "assets/default/inc/images/arrow_right_p.res"
#include "assets/default/inc/images/arrow_up_n.res"
#include "assets/default/inc/images/arrow_up_o.res"
#include "assets/default/inc/images/arrow_up_p.res"
#include "assets/default/inc/images/backspace.res"
#include "assets/default/inc/images/battery_0.res"
#include "assets/default/inc/images/battery_1.res"
#include "assets/default/inc/images/battery_2.res"
#include "assets/default/inc/images/battery_3.res"
#include "assets/default/inc/images/battery_4.res"
#include "assets/default/inc/images/battery_5.res"
#include "assets/default/inc/images/bee.res"
#include "assets/default/inc/images/bricks.res"
#include "assets/default/inc/images/check.res"
#include "assets/default/inc/images/checked.res"
#include "assets/default/inc/images/clock.res"
#include "assets/default/inc/images/clock_bg.res"
#include "assets/default/inc/images/clock_hour.res"
#include "assets/default/inc/images/clock_minute.res"
#include "assets/default/inc/images/clock_second.res"
#include "assets/default/inc/images/close_d.res"
#include "assets/default/inc/images/close_n.res"
#include "assets/default/inc/images/close_o.res"
#include "assets/default/inc/images/close_p.res"
#include "assets/default/inc/images/contact.res"
#include "assets/default/inc/images/contact_active.res"
#include "assets/default/inc/images/cross.res"
#include "assets/default/inc/images/cursor.res"
#include "assets/default/inc/images/dialog_title.res"
#include "assets/default/inc/images/discovery.res"
#include "assets/default/inc/images/discovery_active.res"
#include "assets/default/inc/images/dot.res"
#include "assets/default/inc/images/earth.res"
#include "assets/default/inc/images/edit_clear_n.res"
#include "assets/default/inc/images/edit_clear_o.res"
#include "assets/default/inc/images/edit_clear_p.res"
#include "assets/default/inc/images/empty.res"
#include "assets/default/inc/images/en.res"
#include "assets/default/inc/images/find.res"
#include "assets/default/inc/images/green_btn_n.res"
#include "assets/default/inc/images/green_btn_o.res"
#include "assets/default/inc/images/green_btn_p.res"
#include "assets/default/inc/images/guage_bg.res"
#include "assets/default/inc/images/guage_pointer.res"
#include "assets/default/inc/images/info.res"
#include "assets/default/inc/images/invisible.res"
#include "assets/default/inc/images/left_off.res"
#include "assets/default/inc/images/left_on.res"
#include "assets/default/inc/images/logo.res"
#include "assets/default/inc/images/me.res"
#include "assets/default/inc/images/message.res"
#include "assets/default/inc/images/me_active.res"
#include "assets/default/inc/images/middle_off.res"
#include "assets/default/inc/images/middle_on.res"
#include "assets/default/inc/images/msg.res"
#include "assets/default/inc/images/msg_active.res"
#include "assets/default/inc/images/muted.res"
#include "assets/default/inc/images/num_0.res"
#include "assets/default/inc/images/num_1.res"
#include "assets/default/inc/images/num_2.res"
#include "assets/default/inc/images/num_3.res"
#include "assets/default/inc/images/num_4.res"
#include "assets/default/inc/images/num_5.res"
#include "assets/default/inc/images/num_6.res"
#include "assets/default/inc/images/num_7.res"
#include "assets/default/inc/images/num_8.res"
#include "assets/default/inc/images/num_9.res"
#include "assets/default/inc/images/num_dot.res"
#include "assets/default/inc/images/play_n.res"
#include "assets/default/inc/images/play_o.res"
#include "assets/default/inc/images/play_p.res"
#include "assets/default/inc/images/progress_circle.res"
#include "assets/default/inc/images/question.res"
#include "assets/default/inc/images/radio_checked.res"
#include "assets/default/inc/images/radio_unchecked.res"
#include "assets/default/inc/images/red_btn_n.res"
#include "assets/default/inc/images/red_btn_o.res"
#include "assets/default/inc/images/red_btn_p.res"
#include "assets/default/inc/images/rgb.res"
#include "assets/default/inc/images/rgba.res"
#include "assets/default/inc/images/right_off.res"
#include "assets/default/inc/images/right_on.res"
#include "assets/default/inc/images/shift.res"
#include "assets/default/inc/images/shifton.res"
#include "assets/default/inc/images/slider_bg.res"
#include "assets/default/inc/images/slider_drag.res"
#include "assets/default/inc/images/slider_drag_o.res"
#include "assets/default/inc/images/slider_drag_p.res"
#include "assets/default/inc/images/slider_fg.res"
#include "assets/default/inc/images/slider_v_bg.res"
#include "assets/default/inc/images/slider_v_fg.res"
#include "assets/default/inc/images/switch.res"
#include "assets/default/inc/images/unchecked.res"
#include "assets/default/inc/images/unmuted.res"
#include "assets/default/inc/images/visible.res"
#include "assets/default/inc/images/warn.res"
#include "assets/default/inc/images/zh.res"
#else
#include "assets/default/inc/images/1.data"
#include "assets/default/inc/images/2.data"
#include "assets/default/inc/images/3.data"
#include "assets/default/inc/images/active_dot.data"
#include "assets/default/inc/images/ani1.data"
#include "assets/default/inc/images/ani2.data"
#include "assets/default/inc/images/ani3.data"
#include "assets/default/inc/images/ani4.data"
#include "assets/default/inc/images/ani5.data"
#include "assets/default/inc/images/ani6.data"
#include "assets/default/inc/images/ani7.data"
#include "assets/default/inc/images/ani8.data"
#include "assets/default/inc/images/ani9.data"
#include "assets/default/inc/images/ania.data"
#include "assets/default/inc/images/anib.data"
#include "assets/default/inc/images/anic.data"
#include "assets/default/inc/images/arrow_down_n.data"
#include "assets/default/inc/images/arrow_down_o.data"
#include "assets/default/inc/images/arrow_down_p.data"
#include "assets/default/inc/images/arrow_left_n.data"
#include "assets/default/inc/images/arrow_left_o.data"
#include "assets/default/inc/images/arrow_left_p.data"
#include "assets/default/inc/images/arrow_right_n.data"
#include "assets/default/inc/images/arrow_right_o.data"
#include "assets/default/inc/images/arrow_right_p.data"
#include "assets/default/inc/images/arrow_up_n.data"
#include "assets/default/inc/images/arrow_up_o.data"
#include "assets/default/inc/images/arrow_up_p.data"
#include "assets/default/inc/images/backspace.data"
#include "assets/default/inc/images/battery_0.data"
#include "assets/default/inc/images/battery_1.data"
#include "assets/default/inc/images/battery_2.data"
#include "assets/default/inc/images/battery_3.data"
#include "assets/default/inc/images/battery_4.data"
#include "assets/default/inc/images/battery_5.data"
#include "assets/default/inc/images/bee.data"
#include "assets/default/inc/images/bricks.data"
#include "assets/default/inc/images/check.data"
#include "assets/default/inc/images/checked.data"
#include "assets/default/inc/images/clock.data"
#include "assets/default/inc/images/clock_bg.data"
#include "assets/default/inc/images/clock_hour.data"
#include "assets/default/inc/images/clock_minute.data"
#include "assets/default/inc/images/clock_second.data"
#include "assets/default/inc/images/close_d.data"
#include "assets/default/inc/images/close_n.data"
#include "assets/default/inc/images/close_o.data"
#include "assets/default/inc/images/close_p.data"
#include "assets/default/inc/images/contact.data"
#include "assets/default/inc/images/contact_active.data"
#include "assets/default/inc/images/cross.data"
#include "assets/default/inc/images/cursor.data"
#include "assets/default/inc/images/dialog_title.data"
#include "assets/default/inc/images/discovery.data"
#include "assets/default/inc/images/discovery_active.data"
#include "assets/default/inc/images/dot.data"
#include "assets/default/inc/images/earth.data"
#include "assets/default/inc/images/edit_clear_n.data"
#include "assets/default/inc/images/edit_clear_o.data"
#include "assets/default/inc/images/edit_clear_p.data"
#include "assets/default/inc/images/empty.data"
#include "assets/default/inc/images/en.data"
#include "assets/default/inc/images/find.data"
#include "assets/default/inc/images/green_btn_n.data"
#include "assets/default/inc/images/green_btn_o.data"
#include "assets/default/inc/images/green_btn_p.data"
#include "assets/default/inc/images/guage_bg.data"
#include "assets/default/inc/images/guage_pointer.data"
#include "assets/default/inc/images/info.data"
#include "assets/default/inc/images/invisible.data"
#include "assets/default/inc/images/left_off.data"
#include "assets/default/inc/images/left_on.data"
#include "assets/default/inc/images/logo.data"
#include "assets/default/inc/images/me.data"
#include "assets/default/inc/images/message.data"
#include "assets/default/inc/images/me_active.data"
#include "assets/default/inc/images/middle_off.data"
#include "assets/default/inc/images/middle_on.data"
#include "assets/default/inc/images/msg.data"
#include "assets/default/inc/images/msg_active.data"
#include "assets/default/inc/images/muted.data"
#include "assets/default/inc/images/num_0.data"
#include "assets/default/inc/images/num_1.data"
#include "assets/default/inc/images/num_2.data"
#include "assets/default/inc/images/num_3.data"
#include "assets/default/inc/images/num_4.data"
#include "assets/default/inc/images/num_5.data"
#include "assets/default/inc/images/num_6.data"
#include "assets/default/inc/images/num_7.data"
#include "assets/default/inc/images/num_8.data"
#include "assets/default/inc/images/num_9.data"
#include "assets/default/inc/images/num_dot.data"
#include "assets/default/inc/images/play_n.data"
#include "assets/default/inc/images/play_o.data"
#include "assets/default/inc/images/play_p.data"
#include "assets/default/inc/images/progress_circle.data"
#include "assets/default/inc/images/question.data"
#include "assets/default/inc/images/radio_checked.data"
#include "assets/default/inc/images/radio_unchecked.data"
#include "assets/default/inc/images/red_btn_n.data"
#include "assets/default/inc/images/red_btn_o.data"
#include "assets/default/inc/images/red_btn_p.data"
#include "assets/default/inc/images/rgb.data"
#include "assets/default/inc/images/rgba.data"
#include "assets/default/inc/images/right_off.data"
#include "assets/default/inc/images/right_on.data"
#include "assets/default/inc/images/shift.data"
#include "assets/default/inc/images/shifton.data"
#include "assets/default/inc/images/slider_bg.data"
#include "assets/default/inc/images/slider_drag.data"
#include "assets/default/inc/images/slider_drag_o.data"
#include "assets/default/inc/images/slider_drag_p.data"
#include "assets/default/inc/images/slider_fg.data"
#include "assets/default/inc/images/slider_v_bg.data"
#include "assets/default/inc/images/slider_v_fg.data"
#include "assets/default/inc/images/switch.data"
#include "assets/default/inc/images/unchecked.data"
#include "assets/default/inc/images/unmuted.data"
#include "assets/default/inc/images/visible.data"
#include "assets/default/inc/images/warn.data"
#include "assets/default/inc/images/zh.data"
#endif /*WITH_STB_IMAGE*/
#ifdef WITH_VGCANVAS
#include "assets/default/inc/images/ball.bsvg"
#include "assets/default/inc/images/china.bsvg"
#include "assets/default/inc/images/girl.bsvg"
#include "assets/default/inc/images/pointer.bsvg"
#include "assets/default/inc/images/pointer_1.bsvg"
#include "assets/default/inc/images/pointer_4.bsvg"
#endif /*WITH_VGCANVAS*/
#if defined(WITH_TRUETYPE_FONT)
#include "assets/default/inc/fonts/default.res"
#else /*WITH_TRUETYPE_FONT*/
#include "assets/default/inc/fonts/default.data"
#endif /*WITH_TRUETYPE_FONT*/
#endif /*WITH_FS_RES*/

ret_t assets_init(void) {
  assets_manager_t* am = assets_manager();

#ifdef WITH_FS_RES
  assets_manager_preload(am, ASSET_TYPE_FONT, "default");
  assets_manager_preload(am, ASSET_TYPE_STYLE, "default");
#else
  assets_manager_add(am, font_default);
  assets_manager_add(am, image_1);
  assets_manager_add(am, image_2);
  assets_manager_add(am, image_3);
  assets_manager_add(am, image_active_dot);
  assets_manager_add(am, image_ani1);
  assets_manager_add(am, image_ani2);
  assets_manager_add(am, image_ani3);
  assets_manager_add(am, image_ani4);
  assets_manager_add(am, image_ani5);
  assets_manager_add(am, image_ani6);
  assets_manager_add(am, image_ani7);
  assets_manager_add(am, image_ani8);
  assets_manager_add(am, image_ani9);
  assets_manager_add(am, image_ania);
  assets_manager_add(am, image_anib);
  assets_manager_add(am, image_anic);
  assets_manager_add(am, image_arrow_down_n);
  assets_manager_add(am, image_arrow_down_o);
  assets_manager_add(am, image_arrow_down_p);
  assets_manager_add(am, image_arrow_left_n);
  assets_manager_add(am, image_arrow_left_o);
  assets_manager_add(am, image_arrow_left_p);
  assets_manager_add(am, image_arrow_right_n);
  assets_manager_add(am, image_arrow_right_o);
  assets_manager_add(am, image_arrow_right_p);
  assets_manager_add(am, image_arrow_up_n);
  assets_manager_add(am, image_arrow_up_o);
  assets_manager_add(am, image_arrow_up_p);
  assets_manager_add(am, image_backspace);
  assets_manager_add(am, image_battery_0);
  assets_manager_add(am, image_battery_1);
  assets_manager_add(am, image_battery_2);
  assets_manager_add(am, image_battery_3);
  assets_manager_add(am, image_battery_4);
  assets_manager_add(am, image_battery_5);
  assets_manager_add(am, image_bee);
  assets_manager_add(am, image_bricks);
  assets_manager_add(am, image_check);
  assets_manager_add(am, image_checked);
  assets_manager_add(am, image_clock);
  assets_manager_add(am, image_clock_bg);
  assets_manager_add(am, image_clock_hour);
  assets_manager_add(am, image_clock_minute);
  assets_manager_add(am, image_clock_second);
  assets_manager_add(am, image_close_d);
  assets_manager_add(am, image_close_n);
  assets_manager_add(am, image_close_o);
  assets_manager_add(am, image_close_p);
  assets_manager_add(am, image_contact);
  assets_manager_add(am, image_contact_active);
  assets_manager_add(am, image_cross);
  assets_manager_add(am, image_cursor);
  assets_manager_add(am, image_dialog_title);
  assets_manager_add(am, image_discovery);
  assets_manager_add(am, image_discovery_active);
  assets_manager_add(am, image_dot);
  assets_manager_add(am, image_earth);
  assets_manager_add(am, image_edit_clear_n);
  assets_manager_add(am, image_edit_clear_o);
  assets_manager_add(am, image_edit_clear_p);
  assets_manager_add(am, image_empty);
  assets_manager_add(am, image_en);
  assets_manager_add(am, image_find);
  assets_manager_add(am, image_green_btn_n);
  assets_manager_add(am, image_green_btn_o);
  assets_manager_add(am, image_green_btn_p);
  assets_manager_add(am, image_guage_bg);
  assets_manager_add(am, image_guage_pointer);
  assets_manager_add(am, image_info);
  assets_manager_add(am, image_invisible);
  assets_manager_add(am, image_left_off);
  assets_manager_add(am, image_left_on);
  assets_manager_add(am, image_logo);
  assets_manager_add(am, image_me);
  assets_manager_add(am, image_message);
  assets_manager_add(am, image_me_active);
  assets_manager_add(am, image_middle_off);
  assets_manager_add(am, image_middle_on);
  assets_manager_add(am, image_msg);
  assets_manager_add(am, image_msg_active);
  assets_manager_add(am, image_muted);
  assets_manager_add(am, image_num_0);
  assets_manager_add(am, image_num_1);
  assets_manager_add(am, image_num_2);
  assets_manager_add(am, image_num_3);
  assets_manager_add(am, image_num_4);
  assets_manager_add(am, image_num_5);
  assets_manager_add(am, image_num_6);
  assets_manager_add(am, image_num_7);
  assets_manager_add(am, image_num_8);
  assets_manager_add(am, image_num_9);
  assets_manager_add(am, image_num_dot);
  assets_manager_add(am, image_play_n);
  assets_manager_add(am, image_play_o);
  assets_manager_add(am, image_play_p);
  assets_manager_add(am, image_progress_circle);
  assets_manager_add(am, image_question);
  assets_manager_add(am, image_radio_checked);
  assets_manager_add(am, image_radio_unchecked);
  assets_manager_add(am, image_red_btn_n);
  assets_manager_add(am, image_red_btn_o);
  assets_manager_add(am, image_red_btn_p);
  assets_manager_add(am, image_rgb);
  assets_manager_add(am, image_rgba);
  assets_manager_add(am, image_right_off);
  assets_manager_add(am, image_right_on);
  assets_manager_add(am, image_shift);
  assets_manager_add(am, image_shifton);
  assets_manager_add(am, image_slider_bg);
  assets_manager_add(am, image_slider_drag);
  assets_manager_add(am, image_slider_drag_o);
  assets_manager_add(am, image_slider_drag_p);
  assets_manager_add(am, image_slider_fg);
  assets_manager_add(am, image_slider_v_bg);
  assets_manager_add(am, image_slider_v_fg);
  assets_manager_add(am, image_switch);
  assets_manager_add(am, image_unchecked);
  assets_manager_add(am, image_unmuted);
  assets_manager_add(am, image_visible);
  assets_manager_add(am, image_warn);
  assets_manager_add(am, image_zh);
  assets_manager_add(am, strings_en_US);
  assets_manager_add(am, strings_zh_CN);
  assets_manager_add(am, style_default);
  assets_manager_add(am, style_dialog);
  assets_manager_add(am, style_dialog_confirm);
  assets_manager_add(am, style_dialog_info);
  assets_manager_add(am, style_dialog_toast);
  assets_manager_add(am, style_dialog_warn);
  assets_manager_add(am, style_keyboard);
  assets_manager_add(am, style_main);
  assets_manager_add(am, style_window1);
  assets_manager_add(am, ui_books);
  assets_manager_add(am, ui_calculator);
  assets_manager_add(am, ui_custom_handlers);
  assets_manager_add(am, ui_demo9_main);
  assets_manager_add(am, ui_home);
  assets_manager_add(am, ui_humidity);
  assets_manager_add(am, ui_js_address);
  assets_manager_add(am, ui_js_books);
  assets_manager_add(am, ui_js_calculator);
  assets_manager_add(am, ui_js_com_settings);
  assets_manager_add(am, ui_js_demo9_main);
  assets_manager_add(am, ui_js_home);
  assets_manager_add(am, ui_js_humidity);
  assets_manager_add(am, ui_js_room_settings);
  assets_manager_add(am, ui_js_shape);
  assets_manager_add(am, ui_js_temperature1);
  assets_manager_add(am, ui_js_temperature10);
  assets_manager_add(am, ui_js_temperature14);
  assets_manager_add(am, ui_js_temperature17);
  assets_manager_add(am, ui_js_temperature18);
  assets_manager_add(am, ui_js_temperature2);
  assets_manager_add(am, ui_js_temperature3);
  assets_manager_add(am, ui_js_temperature4);
  assets_manager_add(am, ui_js_temperature5);
  assets_manager_add(am, ui_js_temperature6);
  assets_manager_add(am, ui_js_temperature9);
  assets_manager_add(am, ui_js_temperature_humidity);
  assets_manager_add(am, ui_kb_ascii);
  assets_manager_add(am, ui_kb_default);
  assets_manager_add(am, ui_kb_float);
  assets_manager_add(am, ui_kb_hex);
  assets_manager_add(am, ui_kb_int);
  assets_manager_add(am, ui_kb_phone);
  assets_manager_add(am, ui_kb_ufloat);
  assets_manager_add(am, ui_kb_uint);
  assets_manager_add(am, ui_room_settings);
  assets_manager_add(am, ui_shape);
  assets_manager_add(am, ui_temperature1);
  assets_manager_add(am, ui_temperature10);
  assets_manager_add(am, ui_temperature14);
  assets_manager_add(am, ui_temperature16);
  assets_manager_add(am, ui_temperature17);
  assets_manager_add(am, ui_temperature2);
  assets_manager_add(am, ui_temperature3);
  assets_manager_add(am, ui_temperature4);
  assets_manager_add(am, ui_temperature5);
  assets_manager_add(am, ui_temperature6);
  assets_manager_add(am, ui_temperature9);
  assets_manager_add(am, ui_temperature_humidity);
#ifdef WITH_VGCANVAS
  assets_manager_add(am, image_ball);
  assets_manager_add(am, image_china);
  assets_manager_add(am, image_girl);
  assets_manager_add(am, image_pointer);
  assets_manager_add(am, image_pointer_1);
  assets_manager_add(am, image_pointer_4);
#endif /*WITH_VGCANVAS*/
#endif

  tk_init_assets();
  return RET_OK;
}
