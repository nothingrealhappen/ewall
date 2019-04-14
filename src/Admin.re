[@react.component]
let make = () => {
  let goToHome = _ => ReasonReactRouter.push(Route.getRoutePath(Home, true));
  <>
    <h1> {React.string("Admin Panel")} </h1>
    <a href="javascript:;" onClick=goToHome> {React.string("Go Back")} </a>
  </>;
};
