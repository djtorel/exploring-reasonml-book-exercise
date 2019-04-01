let plus1 = x => x + 1;
Js.log(plus1(7));

let listPlus1 = List.map(x => x + 1, [12, 5, 8, 4]);
Js.log(listPlus1);
let arrayPlus1 = Array.map(x => x + 1, [|10, 7, 3, 20|]);
Js.log(arrayPlus1);

let rec even = x =>
  if (x <= 0) {
    true;
  } else {
    odd(x - 1);
  }
and odd = x =>
  if (x <= 0) {
    false;
  } else {
    even(x - 1);
  };

Js.log(even(400));

let rec factorial = x =>
  if (x <= 2) {
    x;
  } else {
    x * factorial(x - 1);
  };

Js.log(factorial(9));

let foo = () => {
  let iteration = ref(0);
  () => {
    iteration := iteration^ + 1;
    iteration^;
  };
};

let bar = foo();
Js.log(bar());
Js.log(bar());
Js.log(bar());
Js.log(bar());

let add = (x, y) => x + y;

let add4 = add(4);

Js.log(add4(5));

let addComponents = ((x: int, y: int)) => x + y;
let tuple = (3, 4);
Js.log(addComponents(tuple));

let add = (~x: int, ~y: int) => x + y;
Js.log(add(~x=7, ~y=9));

let add = (~x: option(int)=?, ~y: option(int)=?, ()) =>
  switch (x, y) {
  | (Some(x'), Some(y')) => x' + y'
  | (Some(x'), None) => x'
  | (None, Some(y')) => y'
  | (None, None) => 0
  };

Js.log(add(~y=1, ()));

let add = (~x: int=0, ~y: int=0, ()) => x + y;
Js.log(add(~y=5, ()));

let multiply = (~x=1, ~y=1, ()) => x * y;
Js.log(multiply(~x=?Some(14), ~y=?None, ()));

let square = (~x=?, ()) => multiply(~x?, ~y=?x, ());
Js.log(square(~x=5, ()));

let add = (x, y) => x + y;
let plus5 = add(5);
Js.log(plus5(4));

let numbers = [11, 2, 8];
let plus2 = x => add(2, x);
Js.log(List.map(plus2, numbers));
Js.log(List.map(add(2), numbers));

let curry2 = (f: (('a, 'b)) => 'c, x, y) => f((x, y));
let add = ((x, y)) => x + y;

Js.log(curry2(add, 2, 4));

let times2 = (x: int) => x * 2;
let twice = (s: string) => s ++ s;

Js.log(4 |> times2 |> string_of_int |> twice);

Js.log(
  [4, 2, 1, 3, 5]
  |> List.map(x => x + 1)
  |> List.filter(x => x < 5)
  |> List.sort(compare),
);

let divTuple =
  fun
  | (_, 0) => (-1)
  | (x, y) => x / y;

Js.log(divTuple((4, 3)));
Js.log(divTuple((1, 0)));

Js.log(4 * 6);

let (+++) = (s, t) => s ++ " " ++ t;
Js.log("Hello" +++ "World");
let add = (x, y) => x + y;
Js.log();

let first = ((x, _)) => x;
Js.log(first((4, 6)));
