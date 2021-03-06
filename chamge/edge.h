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

#ifndef __CHAMGE_EDGE_H__
#define __CHAMGE_EDGE_H__

#if !defined(__CHAMGE_INSIDE__) && !defined(CHAMGE_COMPILATION)
#error "Only <chamge/chamge.h> can be included directly."
#endif

#include <chamge/node.h>

G_BEGIN_DECLS

#define CHAMGE_TYPE_EDGE       (chamge_edge_get_type ())
CHAMGE_API_EXPORT
G_DECLARE_DERIVABLE_TYPE (ChamgeEdge, chamge_edge, CHAMGE, EDGE, ChamgeNode)

struct _ChamgeEdgeClass
{
  ChamgeNodeClass parent_class;
  
  /* methods */
  gchar* (* request_target_uri)         (ChamgeEdge *self, GError **error);


  /* signals */
  void (*user_command)                  (ChamgeEdge    *self,
                                         const gchar   *cmd,
                                         gchar        **response,
                                         GError       **error);
};

CHAMGE_API_EXPORT
ChamgeEdge*    chamge_edge_new                          (const gchar   *uid);

CHAMGE_API_EXPORT
ChamgeEdge*    chamge_edge_new_full                     (const gchar   *uid,
                                                         ChamgeBackend  backend);

CHAMGE_API_EXPORT
gchar*          chamge_edge_request_target_uri          (ChamgeEdge    *self,
                                                         GError       **error);  

G_END_DECLS

#endif // __CHAMGE_EDGE_H__
