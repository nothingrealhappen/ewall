[@react.component]
let make = () => {
  let goAdmin = _e =>
    ReasonReactRouter.push(Route.getRoutePath(Admin, true));

  let settings = Settings.get();

  <>
    <h1> {React.string("Home Page")} </h1>
    <a href="javascript:;" onClick=goAdmin> {React.string("Go Admin")} </a>
    <ul>
      {settings.frames
       |> List.map((frame: Settings.frame) =>
            <li key={frame.url}>
              <h1> {React.string(frame.name)} </h1>
              <a href={frame.url}> {React.string(frame.url)} </a>
            </li>
          )
       |> Array.of_list
       |> ReasonReact.array}
    </ul>
  </>;
};
