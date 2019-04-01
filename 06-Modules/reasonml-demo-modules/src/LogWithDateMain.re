module type LogWithDateInterface = {
  include (module type of Log);
  let logStrWithDate: (string, t) => t;
};

module LogWithDate: LogWithDateInterface = {
  include Log;
  let logStrWithDate = (str: string, log: t) => {
    let dateStr = Js.Date.toISOString(Js.Date.make());
    logStr("[" ++ dateStr ++ "] " ++ str, log);
  };
};

let () =
  LogWithDate.(
    make() |> logStrWithDate("Hello") |> logStrWithDate("everyone") |> print
  );
