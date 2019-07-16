type t;

external create: ([@unboxed] float, [@unboxed] float, [@unboxed] float) => t =
  "rm_create_vec3_byte" "rm_create_vec3";
external get_x: t => float = "rm_vec3_get_x";
external get_y: t => float = "rm_vec3_get_y";
external get_z: t => float = "rm_vec3_get_z";
