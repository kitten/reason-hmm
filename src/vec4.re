type t;

external create: ([@unboxed] float, [@unboxed] float, [@unboxed] float, [@unboxed] float) => t =
  "rm_create_vec4_byte" "rm_create_vec4";
external get_x: t => float = "rm_vec4_get_x";
external get_y: t => float = "rm_vec4_get_y";
external get_z: t => float = "rm_vec4_get_z";
external get_w: t => float = "rm_vec4_get_w";
