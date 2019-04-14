[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let nowShowing =
    switch (Route.getRouteByHash(url.hash)) {
    | Admin => <Admin />
    | Home => <Home />
    | NotFound => <Home />
    };
  ();

  nowShowing;
};
