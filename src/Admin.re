module Card = {
  [@react.component]
  let make = (~url, ~name, ~onDelete) => {
    <section
      style={ReactDOMRe.Style.make(
        ~width="720px",
        ~position="relative",
        ~margin="20px",
        ~boxShadow="0px 8px 18px 1px #777",
        (),
      )}>
      <iframe
        src=url
        style={ReactDOMRe.Style.make(
          ~width="100%",
          ~border="0",
          ~height="400px",
          (),
        )}
      />
      <section
        style={ReactDOMRe.Style.make(
          ~display="flex",
          ~justifyContent="space-between",
          ~padding="15px",
          (),
        )}>
        <h2 style={ReactDOMRe.Style.make(~margin="0", ())}>
          {React.string(name)}
        </h2>
        <input
          defaultValue=url
          style={ReactDOMRe.Style.make(~flexGrow="1", ~margin="0 10px", ())}
        />
        <button onClick=onDelete> {React.string("Delete")} </button>
      </section>
    </section>;
  };
};

let useInput = (initialVal: string) => {
  let (value, setValue) = React.useState(() => initialVal);
  let onChange = e => {
    ReactEvent.Form.target(e)##value |> setValue;
  };
  (value, onChange);
};

[@react.component]
let make = () => {
  let goToHome = _ => ReasonReactRouter.push(Route.getRoutePath(Home, true));

  let (inputName, onNameChange) = useInput("");
  let (inputUrl, onUrlChange) = useInput("");

  let (settings, dispatch) =
    React.useReducer(Settings.reducer, Settings.get());

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    let newFrame: Settings.frame = {name: inputName, url: inputUrl};
    dispatch(Settings.CreateFrame(newFrame));
  };

  let handleDelete = (frame, event) => {
    ReactEvent.Mouse.preventDefault(event);
    dispatch(Settings.DeleteFrame(frame));
  };

  React.useEffect1(
    () => {
      Settings.set(settings);
      None;
    },
    [|settings|],
  );

  <>
    <AppHeader name="Admin" link="<<Home" onLinkClick=goToHome />
    <h3> {React.string("Add New")} </h3>
    <form onSubmit=handleSubmit>
      <label htmlFor="frame-name"> {React.string("Name: ")} </label>
      <input id="frame-name" onChange=onNameChange value=inputName />
      <label htmlFor="frame-url"> {React.string("URL: ")} </label>
      <input id="frame-url" onChange=onUrlChange value=inputUrl />
      <button> {React.string("Submit")} </button>
    </form>
    <section
      style={ReactDOMRe.Style.make(
        ~display="flex",
        ~justifyContent="center",
        ~alignItems="center",
        ~marginTop="20px",
        (),
      )}>
      {settings.frames
       |> List.map((frame: Settings.frame) =>
            <Card
              key={frame.url}
              url={frame.url}
              name={frame.name}
              onDelete={handleDelete(frame)}
            />
          )
       |> Array.of_list
       |> ReasonReact.array}
    </section>
  </>;
};
