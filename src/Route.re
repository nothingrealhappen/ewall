type route =
  | NotFound
  | Admin
  | Home;

let getRoutePath = (route: route, withHash: bool) => {
  let result =
    switch (route) {
    | Admin => "admin"
    | Home => "home"
    | NotFound => ""
    };

  withHash ? "/#" ++ result : result;
};

let getRouteByHash = (hash: 'string): route => {
  switch (hash) {
  | "admin" => Admin
  | "home" => Home
  | _ => NotFound
  };
};
