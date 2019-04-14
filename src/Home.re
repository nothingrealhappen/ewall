[@react.component]
let make = () => {
  let goAdmin = _e =>
    ReasonReactRouter.push(Route.getRoutePath(Admin, true));

  let settings = Settings.get();

  <>
    <AppHeader name="" link="Admin" onLinkClick=goAdmin />
    <p>
      {React.string(
         "Go to Admin page, try to add some name and url(will used by iframe src, i.e.: any website), then see the result.",
       )}
    </p>
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
