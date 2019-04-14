[@react.component]
let make = (~name, ~link, ~onLinkClick) => {
  <header
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~justifyContent="space-between",
      ~alignItems="center",
      ~backgroundColor="#000",
      ~padding="10px",
      ~color="#fff",
      (),
    )}>
    <h1 style={ReactDOMRe.Style.make(~margin="0", ())}>
      {React.string("Ewall")}
    </h1>
    <h2 style={ReactDOMRe.Style.make(~margin="0", ())}>
      {React.string(name)}
    </h2>
    <a
      style={ReactDOMRe.Style.make(~color="#fff", ~textDecoration="none", ())}
      href="javascript:;"
      onClick=onLinkClick>
      {React.string(link)}
    </a>
  </header>;
};
