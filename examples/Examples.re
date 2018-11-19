module Hook = FlatReact.Hook;
module Event = FlatReact.Event;
module Element = FlatReact.Element;

let setTitle: string => unit = [%raw "function(t){document.title = t}"];

let controledInput = () => {
  let (value, setValue) = Hook.useState("test");
  Hook.useEffect(() => Js.log(value));
  let onChange = event =>
    setValue(FlatReact.Event.Form.target(event)##value);

  Element.(div([input_(~value, ~onChange, []), span([str(value)])]));
};

let withUseEffect = () => {
  let (value, setValue) = Hook.useState("Examples");
  Hook.useEffect(() => setTitle(value));
  let onChange = event => setValue(Event.Form.target(event)##value);

  Element.(
    div([
      str("Change document title: "),
      input_(~value, ~onChange, []),
      h3(~className="tagged", [span([str("YES")])]),
    ])
  );
};

type kind =
  | Primary
  | Secondary;

type btnProps = {kind};

let btn = p1 => {
  let cls =
    switch (p1.kind) {
    | Primary => "btn-primary"
    | Secondary => "btn-secondary"
    };
  let children = FlatReact.extractChildren(p1);

  Element.button(~className=cls, ~ariaSetsize=12, [children]);
};

let withKeys = () => {
  let items = ["one", "two", "three"];
  let lis =
    items |> List.map(text => Element.li(~key=text, [Element.str(text)]));

  Element.(ul(lis));
};

let withRef = () => {
  let inputRef = Hook.useDomRef();

  let onClick = _ => inputRef |> Hook.DomRef.currentGet |> Js.log;

  Element.(
    div([
      button(~ref_=inputRef, ~onClick, [str("Click and check console")]),
    ])
  );
};

type theme =
  | Light
  | Dark;

module MyContext =
  FlatReact.Context.Make({
    type t = theme;
    let defaultValue = Some(Dark);
  });

type withContextChildProps = {text: string};
let withContextChild = props => {
  let theme = MyContext.use();
  let innerText =
    switch (theme) {
    | Light => "light fun theme "
    | Dark => "dark cool theme"
    };

  Element.(div([str(props.text ++ ": " ++ innerText)]));
};

let withContext = () => {
  let (theme, setTheme) = Hook.useState(Dark);
  let onClick = _ => setTheme(theme === Dark ? Light : Dark);

  Element.(
    div([
      r(
        MyContext.provider,
        {value: theme},
        [
          str("Themed"),
          r(withContextChild, {text: "Should be themed"}, []),
          button(~onClick, [str("Change theme")]),
        ],
      ),
    ])
  );
};

let examples: list((string, FlatReact.reactElement)) =
  FlatReact.Element.[
    ("Hello, world", str("Hello, world!")),
    ("Controled input", r(controledInput, (), [])),
    ("useEffect", r(withUseEffect, (), [])),
    ("Primary button", r(btn, {kind: Primary}, [str("CLICK ME")])),
    ("Secondary button", r(btn, {kind: Secondary}, [str("click me")])),
    ("With keys", r(withKeys, (), [])),
    ("With ref", r(withRef, (), [])),
    ("With context", r(withContext, (), [])),
  ];

/* Examples render */

type exampleProps = {title: string};

let exampleWrapper = p1 => {
  let children = FlatReact.extractChildren(p1);

  Element.(
    div(~className="example", [h3([str(p1.title)]), children, hr([])])
  );
};

type containerProps = {examples: list((string, FlatReact.reactElement))};

let container = p1 => {
  let mapper = ((title, ex)) =>
    Element.r(exampleWrapper, {title: title}, [ex]);
  let exs = p1.examples |> List.map(mapper);
  Element.div(exs);
};

let target = [%raw "document.getElementById('app')"];

FlatReact.Dom.render(
  Element.r(container, {examples: examples}, []),
  target,
);
