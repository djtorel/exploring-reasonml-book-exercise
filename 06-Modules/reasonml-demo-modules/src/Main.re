module Math = {
  module Tools = {
    let times = (x, y) => x * y;
    let square = x => times(x, x);
  };
};

let () = {
  print_string("Result: ");
  print_int(Math.Tools.square(4));
  print_newline();
};
