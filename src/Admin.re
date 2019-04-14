module Card = {
  [@react.component]
  let make = (~url, ~name) => {
    <section
      style={ReactDOMRe.Style.make(
        ~width="300px",
        ~height="200px",
        ~position="relative",
        (),
      )}>
      <iframe
        src=url
        style={ReactDOMRe.Style.make(~width="100%", ~height="100%", ())}
      />
      <input value=url />
      <h2> {React.string(name)} </h2>
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
  let settings = Settings.get();

  let (frames, setFrames) = React.useState(() => []);
  let (inputName, onNameChange) = useInput("");
  let (inputUrl, onUrlChange) = useInput("");

  Js.log(inputName);

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
  };
  <>
    <h1> {React.string("Admin Panel")} </h1>
    <a href="javascript:;" onClick=goToHome> {React.string("Go Back")} </a>
    <form onSubmit=handleSubmit>
      <label htmlFor="frame-name"> {React.string("Name: ")} </label>
      <input id="frame-name" onChange=onNameChange value=inputName />
      <label htmlFor="frame-url"> {React.string("URL: ")} </label>
      <input id="frame-url" onChange=onUrlChange value=inputUrl />
      <button> {React.string("Submit")} </button>
    </form>
    <section>
      {settings.frames
       |> List.map((frame: Settings.frame) =>
            <Card key={frame.url} url={frame.url} name={frame.name} />
          )
       |> Array.of_list
       |> ReasonReact.array}
    </section>
  </>;
};
