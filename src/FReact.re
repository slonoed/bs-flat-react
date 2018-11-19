type reactElement = FReact_Element.t;

/* Public React API */
/* create element from component */
let createElement:
  ('p => reactElement, 'p, list(reactElement)) => reactElement =
  (foo, p, children) =>
    FReact_Element.rawCreateElement(foo, p, Array.of_list(children));

module Dom = {
  [@bs.module "react-dom"]
  external render: (reactElement, 'a) => unit = "render";
  [@bs.module "react-dom"]
  external hydrate: (reactElement, 'a) => unit = "hydrate";
};

module Event = FReact_Event;

module Hook = FReact_Hook;

module Context = FReact_Context;

module Element = {
  include FReact_Element;
  let r = createElement;
};

let extractChildren = a: Element.t => {
  let l = [%raw "a.children"];
  l;
};
