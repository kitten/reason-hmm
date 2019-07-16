type t;

external create: ([@unboxed] float, [@unboxed] float) => t =
  "rm_create_vec2_byte" "rm_create_vec2";
external get_x: t => float = "rm_vec2_get_x";
external get_y: t => float = "rm_vec2_get_y";
