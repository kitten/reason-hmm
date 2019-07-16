type t;

external create: unit => t = "rm_create_mat4";
external diagonal: ([@unboxed] float) => t = "rm_create_mat4d_byte" "rm_create_mat4d";
external get: (t, int, int) => float = "rm_mat4_get";
external orthographic: (float, float, float, float, float, float) => t =
  "rm_orthographic_byte" "rm_orthographic";
external perspective: (float, float, float, float) => t = "rm_perspective";
external lookat: (Vec3.t, Vec3.t, Vec3.t) => t = "rm_lookat";
external translate: Vec3.t => t = "rm_mat4_translate";
external rotate: (float, Vec3.t) => t = "rm_mat4_rotate";
external scale: Vec3.t => t = "rm_mat4_scale";
external multiply: (t, t) => t = "rm_mat4_multiply";
