type frame = {
  name: string,
  url: string,
};

type settings = {frames: list(frame)};

let localStorageNameSpace = "__ewall__";
let defaultSettings: settings = {frames: []};

let set = (settings: settings) =>
  switch (Js.Json.stringifyAny(settings)) {
  | None => ()
  | Some(stringifiedSettings) =>
    Dom.Storage.(
      setItem(localStorageNameSpace, stringifiedSettings, localStorage)
    )
  };

[@bs.val] external unsafeJsonParse: string => 'a = "JSON.parse";
let get = (): settings =>
  switch (Dom.Storage.(getItem(localStorageNameSpace, localStorage))) {
  | None => defaultSettings
  | Some(settings) => unsafeJsonParse(settings)
  };
