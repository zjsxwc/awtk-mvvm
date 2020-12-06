/**
 * File:   navigator.c
 * Author: AWTK Develop Team
 * Brief:  navigator navigator
 *
 * Copyright (c) 2019 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-01-29 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/value.h"
#include "tkc/utils.h"
#include "tkc/object_default.h"
#include "mvvm/base/navigator.h"

static ret_t navigator_on_destroy(object_t* obj) {
  navigator_t* nav = NAVIGATOR(obj);

  object_unref(OBJECT(nav->handlers));

  return RET_OK;
}

static const object_vtable_t s_navigator_vtable = {.type = "navigator",
                                                   .desc = "navigator",
                                                   .size = sizeof(navigator_t),
                                                   .is_collection = FALSE,
                                                   .on_destroy = navigator_on_destroy};

navigator_t* navigator_create(void) {
  object_t* obj = NULL;
  navigator_t* nav = NULL;

  obj = object_create(&s_navigator_vtable);
  nav = NAVIGATOR(obj);
  return_value_if_fail(obj != NULL, NULL);

  nav->handlers = object_default_create();
  if (nav->handlers == NULL) {
    object_unref(obj);
    obj = NULL;
  }

  return nav;
}

static navigator_handler_t* navigator_find_handler(navigator_t* nav, const char* target) {
  navigator_handler_t* handler = NULL;
  return_value_if_fail(nav != NULL && target != NULL, NULL);
  handler = (navigator_handler_t*)object_get_prop_object(nav->handlers, target);
  if (handler == NULL) {
    handler =
        (navigator_handler_t*)object_get_prop_object(nav->handlers, NAVIGATOR_DEFAULT_HANDLER);
  }

  return handler;
}

ret_t navigator_handle_request(navigator_t* nav, navigator_request_t* req) {
  navigator_handler_t* handler = NULL;
  return_value_if_fail(nav != NULL && req != NULL, RET_BAD_PARAMS);

  handler = navigator_find_handler(nav, req->target);
  if (handler == NULL) {
    handler = navigator_find_handler(nav, NAVIGATOR_DEFAULT_HANDLER);
  }

  if (handler == NULL) {
    log_warn("not found %s\n", req->target);
  }
  return_value_if_fail(handler != NULL, RET_NOT_FOUND);

  return navigator_handler_on_request(handler, req);
}

ret_t navigator_register_handler(navigator_t* nav, const char* name, navigator_handler_t* handler) {
  ret_t ret = RET_OK;
  return_value_if_fail(nav != NULL && name != NULL && handler != NULL, RET_BAD_PARAMS);

  ret = object_set_prop_object(nav->handlers, name, OBJECT(handler));
  assert(OBJECT(handler)->ref_count > 1);
  object_unref(OBJECT(handler));

  log_debug("navigator_register_handler ret=%d : %s\n", ret, name);

  return ret;
}

bool_t navigator_has_handler(navigator_t* nav, const char* name) {
  return_value_if_fail(nav != NULL && name != NULL, RET_BAD_PARAMS);

  return object_get_prop_object(nav->handlers, name) != NULL;
}

ret_t navigator_unregister_handler(navigator_t* nav, const char* name) {
  return_value_if_fail(nav != NULL && name != NULL, RET_BAD_PARAMS);

  object_remove_prop(OBJECT(nav->handlers), name);

  return RET_OK;
}

static navigator_t* s_navigator;
ret_t navigator_set(navigator_t* nav) {
  s_navigator = nav;

  return RET_OK;
}

navigator_t* navigator(void) {
  return s_navigator;
}

ret_t navigator_to(const char* target) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(target != NULL && navigator() != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(target, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_replace(const char* target) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(target != NULL && navigator() != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(target, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  navigator_request_set_close_current(req, TRUE);
  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_switch_to(const char* target, bool_t close_current) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(target != NULL && navigator() != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(target, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  navigator_request_set_open_new(req, FALSE);
  navigator_request_set_close_current(req, close_current);
  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_to_with_key_value(const char* target, const char* key, const char* value) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(target != NULL && navigator() != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(target, NULL);
  return_value_if_fail(req != NULL, RET_OOM);
  object_set_prop_str(OBJECT(req), key, value);
  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_back_to_home(void) {
  return navigator_to(NAVIGATOR_REQ_HOME);
}

ret_t navigator_back(void) {
  return navigator_to(NAVIGATOR_REQ_BACK);
}

ret_t navigator_to_ex(navigator_request_t* req) {
  return navigator_handle_request(navigator(), req);
}

ret_t navigator_toast(const char* content, uint32_t timeout) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(content != NULL, RET_BAD_PARAMS);
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_TOAST, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_CONTENT, content);
  object_set_prop_int(OBJECT(req), NAVIGATOR_ARG_DURATION, timeout);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_info(const char* title, const char* content) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && content != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_INFO, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_CONTENT, content);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_warn(const char* title, const char* content) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && content != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_WARN, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_CONTENT, content);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_confirm(const char* title, const char* content) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && content != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_CONFIRM, NULL);
  return_value_if_fail(req != NULL, RET_OOM);

  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_CONTENT, content);

  ret = navigator_handle_request(navigator(), req);
  if (ret == RET_OK) {
    ret = (ret_t)value_int(&(req->result));
  }

  object_unref(OBJECT(req));

  return ret;
}

static ret_t on_str_result(navigator_request_t* req, const value_t* result) {
  str_t* str = (str_t*)(req->user_data);
  return_value_if_fail(str != NULL && result != NULL, RET_BAD_PARAMS);

  return str_set(str, value_str(result));
}

ret_t navigator_pick_dir(const char* title, str_t* result) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && result != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_PICK_DIR, on_str_result);
  return_value_if_fail(req != NULL, RET_OOM);

  req->user_data = result;
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_DEFAULT, result->str);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_pick_color(const char* title, str_t* result) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && result != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_PICK_COLOR, on_str_result);
  return_value_if_fail(req != NULL, RET_OOM);

  req->user_data = result;
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_DEFAULT, result->str);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_pick_file(const char* title, const char* filter, bool_t for_save, str_t* result) {
  ret_t ret = RET_OK;
  navigator_request_t* req = NULL;
  return_value_if_fail(navigator() != NULL, RET_BAD_PARAMS);
  return_value_if_fail(title != NULL && result != NULL, RET_BAD_PARAMS);

  req = navigator_request_create(NAVIGATOR_REQ_PICK_FILE, on_str_result);
  return_value_if_fail(req != NULL, RET_OOM);

  req->user_data = result;
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_TITLE, title);
  object_set_prop_int(OBJECT(req), NAVIGATOR_ARG_FOR_SAVE, for_save);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_DEFAULT, result->str);
  object_set_prop_str(OBJECT(req), NAVIGATOR_ARG_FILTER, filter);

  ret = navigator_handle_request(navigator(), req);
  object_unref(OBJECT(req));

  return ret;
}

ret_t navigator_close(const char* name) {
  char target[MAX_PATH + 1];
  return_value_if_fail(name != NULL, RET_BAD_PARAMS);

  tk_snprintf(target, sizeof(target) - 1, "%s?%s=%s", NAVIGATOR_REQ_CLOSE, NAVIGATOR_ARG_NAME,
              name);

  return navigator_to(target);
}