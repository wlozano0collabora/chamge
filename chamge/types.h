/**
 *  Copyright 2019 SK Telecom Co., Ltd.
 *    Author: Jeongseok Kim <jeongseok.kim@sk.com>
 *            Heekyoung Seo <hkseo@sk.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#ifndef __CHAMGE_TYPES_H__
#define __CHAMGE_TYPES_H__

#if !defined(__CHAMGE_INSIDE__) && !defined(CHAMGE_COMPILATION)
#error "Only <chamge/chamge.h> can be included directly."
#endif

#include <gmodule.h>

#ifndef _CHAMGE_EXTERN
#define _CHAMGE_EXTERN         extern
#endif

#define CHAMGE_API_EXPORT      _CHAMGE_EXTERN

typedef enum {
  CHAMGE_RETURN_FAIL = -1,
  CHAMGE_RETURN_OK,
  CHAMGE_RETURN_ASYNC,
} ChamgeReturn;

typedef enum {
  CHAMGE_BACKEND_UNKNOWN = 0,
  CHAMGE_BACKEND_MOCK,
  CHAMGE_BACKEND_AMQP,
} ChamgeBackend;

#define CHAMGE_BACKEND_ERROR      (chamge_backend_error_quark())
GQuark chamge_backend_error_quark (void);

typedef enum {
  CHAMGE_BACKEND_ERROR_INVALID_PARAMETER = 1,
  CHAMGE_BACKEND_ERROR_OPERATION_FAILURE,
  CHAMGE_BACKEND_ERROR_INACCESSIBLE,
  CHAMGE_BACKEND_ERROR_MISSING_PARAMETER,
} ChamgeBackendError;

#endif // __CHAMGE_TYPES_H__
