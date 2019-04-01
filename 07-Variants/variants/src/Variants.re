type color =
  | Red
  | Orange
  | Yellow
  | Green
  | Blue
  | Purple;

let invert = (c: color) =>
  switch (c) {
  | Red => Green
  | Orange => Blue
  | Yellow => Purple
  | Green => Red
  | Blue => Orange
  | Purple => Yellow
  };

Js.log(invert(Orange));

let stringOfColor = (c: color) =>
  switch (c) {
  | Red => "Red"
  | Orange => "Orange"
  | Yellow => "Yellow"
  | Green => "Green"
  | Blue => "Blue"
  | Purple => "Purple"
  };

Js.log(stringOfColor(Purple));
Js.log(
  "Inverse of "
  ++ stringOfColor(Purple)
  ++ " is "
  ++ stringOfColor(invert(Purple)),
);

type point =
  | Point(float, float);
type shape =
  | Rectangle(point, point)
  | Circle(point, float);

let bottomLeft = Point(-1.0, -2.0);
let topRight = Point(7.0, 6.0);
let circ = Circle(topRight, 5.0);
let rect = Rectangle(bottomLeft, topRight);

let pi = 4.0 *. atan(1.0);
let computeArea = (s: shape) =>
  switch (s) {
  | Rectangle(Point(x1, y1), Point(x2, y2)) =>
    let width = abs_float(x2 -. x1);
    let height = abs_float(y2 -. y1);
    width *. height;
  | Circle(_, radius) => pi *. radius ** 2.0
  };

Js.log(computeArea(circ));
Js.log(computeArea(rect));

type tree('a) =
  | Empty
  | Node('a, tree('a), tree('a));

type intTree = tree(int);

let myIntTree =
  Node(1, Node(2, Empty, Empty), Node(3, Node(4, Empty, Empty), Empty));

let rec computeSum = (t: intTree) =>
  switch (t) {
  | Empty => 0
  | Node(i, leftTree, rightTree) =>
    i + computeSum(leftTree) + computeSum(rightTree)
  };

Js.log(computeSum(myIntTree));

let myStrTree =
  Node(
    "a",
    Node("b", Empty, Empty),
    Node("c", Node("d", Empty, Empty), Empty),
  );

let rec stringOfTree = (~indent=0, ~stringOfValue: 'a => string, t: tree('a)) => {
  let indentStr = String.make(indent * 2, ' ');
  switch (t) {
  | Empty => indentStr ++ "X" ++ "\n"
  | Node(x, leftTree, rightTree) =>
    indentStr
    ++ stringOfValue(x)
    ++ "\n"
    ++ stringOfTree(~indent=indent + 1, ~stringOfValue, leftTree)
    ++ stringOfTree(~indent=indent + 1, ~stringOfValue, rightTree)
  };
};

Js.log(stringOfTree(~stringOfValue=x => x, myStrTree));
Js.log(stringOfTree(~stringOfValue=string_of_int, myIntTree));

type expression =
  | Plus(expression, expression)
  | Minus(expression, expression)
  | Times(expression, expression)
  | DividedBy(expression, expression)
  | Literal(int);

let expr =
  Minus(
    Literal(3),
    DividedBy(Literal(16), Plus(Literal(6), Literal(2))),
  );

let rec eval = (e: expression) =>
  switch (e) {
  | Plus(e1, e2) => eval(e1) + eval(e2)
  | Minus(e1, e2) => eval(e1) - eval(e2)
  | Times(e1, e2) => eval(e1) * eval(e2)
  | DividedBy(e1, e2) => eval(e1) / eval(e2)
  | Literal(i) => i
  };

Js.log(eval(expr));
