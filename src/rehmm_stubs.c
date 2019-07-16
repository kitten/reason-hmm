#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <caml/custom.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/mlvalues.h>
#include <caml/fail.h>

#define HANDMADE_MATH_IMPLEMENTATION
#define HANDMADE_MATH_NO_SSE

#include "include/HandmadeMath.h"

/*-- vec2 --------------------------------------------------------*/

#define Vec2_custom(v) *((hmm_vec2*)Data_custom_val(v))

int _rm_compare_vec2(value v1, value v2) {
  hmm_vec2 vec1 = Vec2_custom(v1);
  hmm_vec2 vec2 = Vec2_custom(v2);
  if (HMM_EqualsVec2(vec1, vec2)) {
    return 0;
  }

  float vec1_mag = HMM_LengthSquaredVec2(vec1);
  float vec2_mag = HMM_LengthSquaredVec2(vec2);
  return vec1_mag > vec2_mag ? 1 : -1;
}

static struct custom_operations _rm_vec2 = {
  .identifier = "rm_vec2",
  .finalize = custom_finalize_default,
  .compare = _rm_compare_vec2,
  .hash = custom_hash_default,
  .serialize = custom_serialize_default,
  .deserialize = custom_deserialize_default,
};

static inline value _rm_box_vec2(hmm_vec2 vec) {
  value res = caml_alloc_custom(&_rm_vec2, sizeof(float) * 2, 0, 1);
  memcpy(Data_custom_val(res), &vec, sizeof(float) * 2);
  return res;
}

CAMLprim value rm_create_vec2(double x, double y) {
  CAMLparam0();
  CAMLlocal1(v);
  v = _rm_box_vec2(HMM_Vec2((float) x, (float) y));
  CAMLreturn(v);
}

CAMLprim value rm_create_vec2_byte(value x, value y) {
  CAMLparam2(x, y);
  CAMLlocal1(v);
  v = _rm_box_vec2(HMM_Vec2((float) Double_val(x), (float) Double_val(y)));
  CAMLreturn(v);
}

CAMLprim value hmm_vec2_get_x(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(x);
  hmm_vec2 v = Vec2_custom(vec);
  x = caml_copy_double(v.X);
  CAMLreturn(x);
}

CAMLprim value hmm_vec2_get_y(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(y);
  hmm_vec2 v = Vec2_custom(vec);
  y = caml_copy_double(v.Y);
  CAMLreturn(y);
}

/*-- vec3 --------------------------------------------------------*/

#define Vec3_custom(v) *((hmm_vec3*)Data_custom_val(v))

int _rm_compare_vec3(value v1, value v2) {
  hmm_vec3 vec1 = Vec3_custom(v1);
  hmm_vec3 vec2 = Vec3_custom(v2);
  if (HMM_EqualsVec3(vec1, vec2)) {
    return 0;
  }

  float vec1_mag = HMM_LengthSquaredVec3(vec1);
  float vec2_mag = HMM_LengthSquaredVec3(vec2);
  return vec1_mag > vec2_mag ? 1 : -1;
}

static struct custom_operations _rm_vec3 = {
  .identifier = "rm_vec3",
  .finalize = custom_finalize_default,
  .compare = _rm_compare_vec3,
  .hash = custom_hash_default,
  .serialize = custom_serialize_default,
  .deserialize = custom_deserialize_default,
};

static inline value _rm_box_vec3(hmm_vec3 vec) {
  CAMLparam0();
  CAMLlocal1(res);
  res = caml_alloc_custom(&_rm_vec3, sizeof(float) * 3, 0, 1);
  memcpy(Data_custom_val(res), &vec, sizeof(float) * 3);
  CAMLreturn(res);
}

CAMLprim value rm_create_vec3(double x, double y, double z) {
  CAMLparam0();
  CAMLlocal1(v);
  v = _rm_box_vec3(HMM_Vec3((float) x, (float) y, (float) z));
  CAMLreturn(v);
}

CAMLprim value rm_create_vec3_byte(value x, value y, value z) {
  CAMLparam3(x, y, z);
  CAMLlocal1(v);

  v = _rm_box_vec3(HMM_Vec3(
    (float) Double_val(x),
    (float) Double_val(y),
    (float) Double_val(z)
  ));

  CAMLreturn(v);
}

CAMLprim value rm_vec3_get_x(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(x);
  hmm_vec3 v = Vec3_custom(vec);
  x = caml_copy_double(v.X);
  CAMLreturn(x);
}

CAMLprim value rm_vec3_get_y(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(y);
  hmm_vec3 v = Vec3_custom(vec);
  y = caml_copy_double(v.Y);
  CAMLreturn(y);
}

CAMLprim value rm_vec3_get_z(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(z);
  hmm_vec3 v = Vec3_custom(vec);
  z = caml_copy_double(v.Z);
  CAMLreturn(z);
}

/*-- vec4 --------------------------------------------------------*/

#define Vec4_custom(v) *((hmm_vec4*)Data_custom_val(v))

int _rm_compare_vec4(value v1, value v2) {
  hmm_vec4 vec1 = Vec4_custom(v1);
  hmm_vec4 vec2 = Vec4_custom(v2);
  if (HMM_EqualsVec4(vec1, vec2)) {
    return 0;
  }

  float vec1_mag = HMM_LengthSquaredVec4(vec1);
  float vec2_mag = HMM_LengthSquaredVec4(vec2);
  return vec1_mag > vec2_mag ? 1 : -1;
}

static struct custom_operations _rm_vec4 = {
  .identifier = "rm_vec4",
  .finalize = custom_finalize_default,
  .compare = _rm_compare_vec3,
  .hash = custom_hash_default,
  .serialize = custom_serialize_default,
  .deserialize = custom_deserialize_default,
};

static inline value _rm_box_vec4(hmm_vec4 vec) {
  value res = caml_alloc_custom(&_rm_vec4, sizeof(float) * 4, 0, 1);
  memcpy(Data_custom_val(res), &vec, sizeof(float) * 4);
  return res;
}

CAMLprim value rm_create_vec4(double x, double y, double z, double w) {
  CAMLparam0();
  CAMLlocal1(v);
  v = _rm_box_vec4(HMM_Vec4((float) x, (float) y, (float) z, (float) w));
  CAMLreturn(v);
}

CAMLprim value rm_create_vec4_byte(value x, value y, value z, value w) {
  CAMLparam4(x, y, z, w);
  CAMLlocal1(v);

  v = _rm_box_vec4(HMM_Vec4(
    (float) Double_val(x),
    (float) Double_val(y),
    (float) Double_val(z),
    (float) Double_val(w)
  ));

  CAMLreturn(v);
}

CAMLprim value rm_vec4_get_x(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(x);
  hmm_vec4 v = Vec4_custom(vec);
  x = caml_copy_double(v.X);
  CAMLreturn(x);
}

CAMLprim value rm_vec4_get_y(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(y);
  hmm_vec4 v = Vec4_custom(vec);
  y = caml_copy_double(v.Y);
  CAMLreturn(y);
}

CAMLprim value rm_vec4_get_z(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(z);
  hmm_vec4 v = Vec4_custom(vec);
  z = caml_copy_double(v.Z);
  CAMLreturn(z);
}

CAMLprim value rm_vec4_get_w(value vec) {
  CAMLparam1(vec);
  CAMLlocal1(w);
  hmm_vec4 v = Vec4_custom(vec);
  w = caml_copy_double(v.W);
  CAMLreturn(w);
}

/*-- mat4 --------------------------------------------------------*/

#define Mat4_custom(v) *((hmm_mat4*)Data_custom_val(v))

static struct custom_operations _rm_mat4 = {
  .identifier = "hmm_mat4",
  .finalize = custom_finalize_default,
  .compare = custom_compare_default,
  .hash = custom_hash_default,
  .serialize = custom_serialize_default,
  .deserialize = custom_deserialize_default,
};

static inline value _rm_box_mat4(hmm_mat4 vec) {
  value res = caml_alloc_custom(&_rm_mat4, sizeof(float) * 16, 0, 1);
  memcpy(Data_custom_val(res), &vec, sizeof(float) * 16);
  return res;
}

CAMLprim value rm_create_mat4() {
  CAMLparam0();
  CAMLlocal1(v);
  v = _rm_box_mat4(HMM_Mat4());
  CAMLreturn(v);
}

CAMLprim value rm_create_mat4d(double diagonal) {
  CAMLparam0();
  CAMLlocal1(v);
  v = _rm_box_mat4(HMM_Mat4d((float) diagonal));
  CAMLreturn(v);
}

CAMLprim value rm_create_mat4d_byte(value diagonal) {
  CAMLparam1(diagonal);
  CAMLlocal1(v);
  v = _rm_box_mat4(HMM_Mat4d((float) Double_val(diagonal)));
  CAMLreturn(v);
}

CAMLprim value rm_mat4_get(value mat, value row, value column) {
  CAMLparam3(mat, row, column);
  CAMLlocal1(x);
  hmm_mat4 m = Mat4_custom(mat);
  x = caml_copy_double(m.Elements[Int_val(row)][Int_val(column)]);
  CAMLreturn(x);
}

CAMLprim value rm_orthographic(value l, value r, value b, value t, value near, value far) {
  CAMLparam5(l, r, b, t, near);
  CAMLxparam1(far);
  CAMLlocal1(mat);

  mat = _rm_box_mat4(HMM_Orthographic(
    (float) Double_val(l),
    (float) Double_val(r),
    (float) Double_val(b),
    (float) Double_val(t),
    (float) Double_val(near),
    (float) Double_val(far)
  ));

  CAMLreturn(mat);
}

CAMLprim value rm_orthographic_byte(value* argv, int _argn) {
  return rm_orthographic(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value rm_perspective(value fov, value ratio, value near, value far) {
  CAMLparam4(fov, ratio, near, far);
  CAMLlocal1(mat);

  mat = _rm_box_mat4(HMM_Perspective(
    (float) Double_val(fov),
    (float) Double_val(ratio),
    (float) Double_val(near),
    (float) Double_val(far)
  ));

  CAMLreturn(mat);
}

CAMLprim value rm_lookat(value camera, value center, value up) {
  CAMLparam3(camera, center, up);
  CAMLlocal1(mat);

  mat = _rm_box_mat4(HMM_LookAt(
    Vec3_custom(camera),
    Vec3_custom(center),
    Vec3_custom(up)
  ));

  CAMLreturn(mat);
}

CAMLprim value rm_mat4_translate(value translation) {
  CAMLparam1(translation);
  CAMLlocal1(mat);
  mat = _rm_box_mat4(HMM_Translate(Vec3_custom(translation)));
  CAMLreturn(mat);
}

CAMLprim value rm_mat4_rotate(value angle, value axis) {
  CAMLparam2(angle, axis);
  CAMLlocal1(mat);
  mat = _rm_box_mat4(HMM_Rotate(Double_val(angle), Vec3_custom(axis)));
  CAMLreturn(mat);
}

CAMLprim value rm_mat4_scale(value scale) {
  CAMLparam1(scale);
  CAMLlocal1(mat);
  mat = _rm_box_mat4(HMM_Scale(Vec3_custom(scale)));
  CAMLreturn(mat);
}

CAMLprim value rm_mat4_multiply(value a, value b) {
  CAMLparam2(a, b);
  CAMLlocal1(mat);
  mat = _rm_box_mat4(HMM_MultiplyMat4(Mat4_custom(a), Mat4_custom(b)));
  CAMLreturn(mat);
}
