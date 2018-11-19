type reactElement = FlatReact_Element.t;

/* create element from component */
let createElement:
  ('p => reactElement, 'p, list(reactElement)) => reactElement =
  (foo, p, children) =>
    FlatReact_Element.rawCreateElement(foo, p, Array.of_list(children));

module Dom = {
  [@bs.module "react-dom"]
  external render: (reactElement, 'a) => unit = "render";
  [@bs.module "react-dom"]
  external hydrate: (reactElement, 'a) => unit = "hydrate";
};

module Event = FlatReact_Event;

module Hook = FlatReact_Hook;

module Context = FlatReact_Context;

module Element = {
  include FlatReact_Element;
  let r = createElement;
};

let extractChildren = Element.extractChildren;
