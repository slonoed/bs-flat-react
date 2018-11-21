module Event = FlatReact_Event;
module Style = FlatReact_Style;
module Hook = FlatReact_Hook;

type t;
type style = Style.t;
type domRef = Hook.DomRef.t;

let rawCreateElement = (cmp, props, children: array(t)) : t => [%raw
  "require('react').createElement(cmp, props, ...children)"
];

module Props = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    key: string,
    [@bs.optional] [@bs.as "ref"]
    ref_: domRef,
    /* accessibility */
    /* https://www.w3.org/TR/wai-aria-1.1/ */
    /* https://accessibilityresources.org/<aria-tag> is a great resource for these */
    /* [@bs.optional] [@bs.as "aria-current"] ariaCurrent: page|step|location|date|time|true|false, */
    [@bs.optional] [@bs.as "aria-details"]
    ariaDetails: string,
    [@bs.optional] [@bs.as "aria-disabled"]
    ariaDisabled: bool,
    [@bs.optional] [@bs.as "aria-hidden"]
    ariaHidden: bool,
    /* [@bs.optional] [@bs.as "aria-invalid"] ariaInvalid: grammar|false|spelling|true, */
    [@bs.optional] [@bs.as "aria-keyshortcuts"]
    ariaKeyshortcuts: string,
    [@bs.optional] [@bs.as "aria-label"]
    ariaLabel: string,
    [@bs.optional] [@bs.as "aria-roledescription"]
    ariaRoledescription: string,
    /* Widget Attributes */
    /* [@bs.optional] [@bs.as "aria-autocomplete"] ariaAutocomplete: inline|list|both|none, */
    /* [@bs.optional] [@bs.as "aria-checked"] ariaChecked: true|false|mixed, /* https://www.w3.org/TR/wai-aria-1.1/#valuetype_tristate */ */
    [@bs.optional] [@bs.as "aria-expanded"]
    ariaExpanded: bool,
    /* [@bs.optional] [@bs.as "aria-haspopup"] ariaHaspopup: false|true|menu|listbox|tree|grid|dialog, */
    [@bs.optional] [@bs.as "aria-level"]
    ariaLevel: int,
    [@bs.optional] [@bs.as "aria-modal"]
    ariaModal: bool,
    [@bs.optional] [@bs.as "aria-multiline"]
    ariaMultiline: bool,
    [@bs.optional] [@bs.as "aria-multiselectable"]
    ariaMultiselectable: bool,
    /* [@bs.optional] [@bs.as "aria-orientation"] ariaOrientation: horizontal|vertical|undefined, */
    [@bs.optional] [@bs.as "aria-placeholder"]
    ariaPlaceholder: string,
    /* [@bs.optional] [@bs.as "aria-pressed"] ariaPressed: true|false|mixed, /* https://www.w3.org/TR/wai-aria-1.1/#valuetype_tristate */ */
    [@bs.optional] [@bs.as "aria-readonly"]
    ariaReadonly: bool,
    [@bs.optional] [@bs.as "aria-required"]
    ariaRequired: bool,
    [@bs.optional] [@bs.as "aria-selected"]
    ariaSelected: bool,
    [@bs.optional] [@bs.as "aria-sort"]
    ariaSort: string,
    [@bs.optional] [@bs.as "aria-valuemax"]
    ariaValuemax: float,
    [@bs.optional] [@bs.as "aria-valuemin"]
    ariaValuemin: float,
    [@bs.optional] [@bs.as "aria-valuenow"]
    ariaValuenow: float,
    [@bs.optional] [@bs.as "aria-valuetext"]
    ariaValuetext: string,
    /* Live Region Attributes */
    [@bs.optional] [@bs.as "aria-atomic"]
    ariaAtomic: bool,
    [@bs.optional] [@bs.as "aria-busy"]
    ariaBusy: bool,
    /* [@bs.optional] [@bs.as "aria-live"] ariaLive: off|polite|assertive|rude, */
    [@bs.optional] [@bs.as "aria-relevant"]
    ariaRelevant: string,
    /* Drag-and-Drop Attributes */
    /* [@bs.optional] [@bs.as "aria-dropeffect"] ariaDropeffect: copy|move|link|execute|popup|none, */
    [@bs.optional] [@bs.as "aria-grabbed"]
    ariaGrabbed: bool,
    /* Relationship Attributes */
    [@bs.optional] [@bs.as "aria-activedescendant"]
    ariaActivedescendant: string,
    [@bs.optional] [@bs.as "aria-colcount"]
    ariaColcount: int,
    [@bs.optional] [@bs.as "aria-colindex"]
    ariaColindex: int,
    [@bs.optional] [@bs.as "aria-colspan"]
    ariaColspan: int,
    [@bs.optional] [@bs.as "aria-controls"]
    ariaControls: string,
    [@bs.optional] [@bs.as "aria-describedby"]
    ariaDescribedby: string,
    [@bs.optional] [@bs.as "aria-errormessage"]
    ariaErrormessage: string,
    [@bs.optional] [@bs.as "aria-flowto"]
    ariaFlowto: string,
    [@bs.optional] [@bs.as "aria-labelledby"]
    ariaLabelledby: string,
    [@bs.optional] [@bs.as "aria-owns"]
    ariaOwns: string,
    [@bs.optional] [@bs.as "aria-posinset"]
    ariaPosinset: int,
    [@bs.optional] [@bs.as "aria-rowcount"]
    ariaRowcount: int,
    [@bs.optional] [@bs.as "aria-rowindex"]
    ariaRowindex: int,
    [@bs.optional] [@bs.as "aria-rowspan"]
    ariaRowspan: int,
    [@bs.optional] [@bs.as "aria-setsize"]
    ariaSetsize: int,
    /* react textarea/input */
    [@bs.optional]
    defaultChecked: bool,
    [@bs.optional]
    defaultValue: string,
    /* global html attributes */
    [@bs.optional]
    accessKey: string,
    [@bs.optional]
    className: string, /* substitute for "class" */
    [@bs.optional]
    contentEditable: bool,
    [@bs.optional]
    contextMenu: string,
    [@bs.optional]
    dir: string, /* "ltr", "rtl" or "auto" */
    [@bs.optional]
    draggable: bool,
    [@bs.optional]
    hidden: bool,
    [@bs.optional]
    id: string,
    [@bs.optional]
    lang: string,
    [@bs.optional]
    role: string, /* ARIA role */
    [@bs.optional]
    style,
    [@bs.optional]
    spellCheck: bool,
    [@bs.optional]
    tabIndex: int,
    [@bs.optional]
    title: string,
    /* html5 microdata */
    [@bs.optional]
    itemID: string,
    [@bs.optional]
    itemProp: string,
    [@bs.optional]
    itemRef: string,
    [@bs.optional]
    itemScope: bool,
    [@bs.optional]
    itemType: string, /* uri */
    /* tag-specific html attributes */
    [@bs.optional]
    accept: string,
    [@bs.optional]
    acceptCharset: string,
    [@bs.optional]
    action: string, /* uri */
    [@bs.optional]
    allowFullScreen: bool,
    [@bs.optional]
    alt: string,
    [@bs.optional]
    async: bool,
    [@bs.optional]
    autoComplete: string, /* has a fixed, but large-ish, set of possible values */
    [@bs.optional]
    autoFocus: bool,
    [@bs.optional]
    autoPlay: bool,
    [@bs.optional]
    challenge: string,
    [@bs.optional]
    charSet: string,
    [@bs.optional]
    checked: bool,
    [@bs.optional]
    cite: string, /* uri */
    [@bs.optional]
    crossOrigin: string, /* anonymous, use-credentials */
    [@bs.optional]
    cols: int,
    [@bs.optional]
    colSpan: int,
    [@bs.optional]
    content: string,
    [@bs.optional]
    controls: bool,
    [@bs.optional]
    coords: string, /* set of values specifying the coordinates of a region */
    [@bs.optional]
    data: string, /* uri */
    [@bs.optional]
    dateTime: string, /* "valid date string with optional time" */
    [@bs.optional]
    default: bool,
    [@bs.optional]
    defer: bool,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    download: string, /* should really be either a boolean, signifying presence, or a string */
    [@bs.optional]
    encType: string, /* "application/x-www-form-urlencoded", "multipart/form-data" or "text/plain" */
    [@bs.optional]
    form: string,
    [@bs.optional]
    formAction: string, /* uri */
    [@bs.optional]
    formTarget: string, /* "_blank", "_self", etc. */
    [@bs.optional]
    formMethod: string, /* "post", "get", "put" */
    [@bs.optional]
    headers: string,
    [@bs.optional]
    height: string, /* in html5 this can only be a number, but in html4 it can ba a percentage as well */
    [@bs.optional]
    high: int,
    [@bs.optional]
    href: string, /* uri */
    [@bs.optional]
    hrefLang: string,
    [@bs.optional]
    htmlFor: string, /* substitute for "for" */
    [@bs.optional]
    httpEquiv: string, /* has a fixed set of possible values */
    [@bs.optional]
    icon: string, /* uri? */
    [@bs.optional]
    inputMode: string, /* "verbatim", "latin", "numeric", etc. */
    [@bs.optional]
    integrity: string,
    [@bs.optional]
    keyType: string,
    [@bs.optional]
    kind: string, /* has a fixed set of possible values */
    [@bs.optional]
    label: string,
    [@bs.optional]
    list: string,
    [@bs.optional]
    loop: bool,
    [@bs.optional]
    low: int,
    [@bs.optional]
    manifest: string, /* uri */
    [@bs.optional]
    max: string, /* should be int or Js.Date.t */
    [@bs.optional]
    maxLength: int,
    [@bs.optional]
    media: string, /* a valid media query */
    [@bs.optional]
    mediaGroup: string,
    [@bs.optional]
    method: string, /* "post" or "get" */
    [@bs.optional]
    min: int,
    [@bs.optional]
    minLength: int,
    [@bs.optional]
    multiple: bool,
    [@bs.optional]
    muted: bool,
    [@bs.optional]
    name: string,
    [@bs.optional]
    nonce: string,
    [@bs.optional]
    noValidate: bool,
    [@bs.optional] [@bs.as "open"]
    open_: bool, /* use this one. Previous one is deprecated */
    [@bs.optional]
    optimum: int,
    [@bs.optional]
    pattern: string, /* valid Js RegExp */
    [@bs.optional]
    placeholder: string,
    [@bs.optional]
    poster: string, /* uri */
    [@bs.optional]
    preload: string, /* "none", "metadata" or "auto" (and "" as a synonym for "auto") */
    [@bs.optional]
    radioGroup: string,
    [@bs.optional]
    readOnly: bool,
    [@bs.optional]
    rel: string, /* a space- or comma-separated (depending on the element) list of a fixed set of "link types" */
    [@bs.optional]
    required: bool,
    [@bs.optional]
    reversed: bool,
    [@bs.optional]
    rows: int,
    [@bs.optional]
    rowSpan: int,
    [@bs.optional]
    sandbox: string, /* has a fixed set of possible values */
    [@bs.optional]
    scope: string, /* has a fixed set of possible values */
    [@bs.optional]
    scoped: bool,
    [@bs.optional]
    scrolling: string, /* html4 only, "auto", "yes" or "no" */
    /* seamless - supported by React, but removed from the html5 spec */
    [@bs.optional]
    selected: bool,
    [@bs.optional]
    shape: string,
    [@bs.optional]
    size: int,
    [@bs.optional]
    sizes: string,
    [@bs.optional]
    span: int,
    [@bs.optional]
    src: string, /* uri */
    [@bs.optional]
    srcDoc: string,
    [@bs.optional]
    srcLang: string,
    [@bs.optional]
    srcSet: string,
    [@bs.optional]
    start: int,
    [@bs.optional]
    step: float,
    [@bs.optional]
    summary: string, /* deprecated */
    [@bs.optional]
    target: string,
    [@bs.optional] [@bs.as "type"]
    type_: string, /* has a fixed but large-ish set of possible values */ /* use this one. Previous one is deprecated */
    [@bs.optional]
    useMap: string,
    [@bs.optional]
    value: string,
    [@bs.optional]
    width: string, /* in html5 this can only be a number, but in html4 it can ba a percentage as well */
    [@bs.optional]
    wrap: string, /* "hard" or "soft" */
    /* Clipboard events */
    [@bs.optional]
    onCopy: Event.Clipboard.t => unit,
    [@bs.optional]
    onCut: Event.Clipboard.t => unit,
    [@bs.optional]
    onPaste: Event.Clipboard.t => unit,
    /* Composition events */
    [@bs.optional]
    onCompositionEnd: Event.Composition.t => unit,
    [@bs.optional]
    onCompositionStart: Event.Composition.t => unit,
    [@bs.optional]
    onCompositionUpdate: Event.Composition.t => unit,
    /* Keyboard events */
    [@bs.optional]
    onKeyDown: Event.Keyboard.t => unit,
    [@bs.optional]
    onKeyPress: Event.Keyboard.t => unit,
    [@bs.optional]
    onKeyUp: Event.Keyboard.t => unit,
    /* Focus events */
    [@bs.optional]
    onFocus: Event.Focus.t => unit,
    [@bs.optional]
    onBlur: Event.Focus.t => unit,
    /* Form events */
    [@bs.optional]
    onChange: Event.Form.t => unit,
    [@bs.optional]
    onInput: Event.Form.t => unit,
    [@bs.optional]
    onSubmit: Event.Form.t => unit,
    /* Mouse events */
    [@bs.optional]
    onClick: Event.Mouse.t => unit,
    [@bs.optional]
    onContextMenu: Event.Mouse.t => unit,
    [@bs.optional]
    onDoubleClick: Event.Mouse.t => unit,
    [@bs.optional]
    onDrag: Event.Mouse.t => unit,
    [@bs.optional]
    onDragEnd: Event.Mouse.t => unit,
    [@bs.optional]
    onDragEnter: Event.Mouse.t => unit,
    [@bs.optional]
    onDragExit: Event.Mouse.t => unit,
    [@bs.optional]
    onDragLeave: Event.Mouse.t => unit,
    [@bs.optional]
    onDragOver: Event.Mouse.t => unit,
    [@bs.optional]
    onDragStart: Event.Mouse.t => unit,
    [@bs.optional]
    onDrop: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseDown: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseEnter: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseLeave: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseMove: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseOut: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseOver: Event.Mouse.t => unit,
    [@bs.optional]
    onMouseUp: Event.Mouse.t => unit,
    /* Selection events */
    [@bs.optional]
    onSelect: Event.Selection.t => unit,
    /* Touch events */
    [@bs.optional]
    onTouchCancel: Event.Touch.t => unit,
    [@bs.optional]
    onTouchEnd: Event.Touch.t => unit,
    [@bs.optional]
    onTouchMove: Event.Touch.t => unit,
    [@bs.optional]
    onTouchStart: Event.Touch.t => unit,
    /* UI events */
    [@bs.optional]
    onScroll: Event.UI.t => unit,
    /* Wheel events */
    [@bs.optional]
    onWheel: Event.Wheel.t => unit,
    /* Media events */
    [@bs.optional]
    onAbort: Event.Media.t => unit,
    [@bs.optional]
    onCanPlay: Event.Media.t => unit,
    [@bs.optional]
    onCanPlayThrough: Event.Media.t => unit,
    [@bs.optional]
    onDurationChange: Event.Media.t => unit,
    [@bs.optional]
    onEmptied: Event.Media.t => unit,
    [@bs.optional]
    onEncrypetd: Event.Media.t => unit,
    [@bs.optional]
    onEnded: Event.Media.t => unit,
    [@bs.optional]
    onError: Event.Media.t => unit,
    [@bs.optional]
    onLoadedData: Event.Media.t => unit,
    [@bs.optional]
    onLoadedMetadata: Event.Media.t => unit,
    [@bs.optional]
    onLoadStart: Event.Media.t => unit,
    [@bs.optional]
    onPause: Event.Media.t => unit,
    [@bs.optional]
    onPlay: Event.Media.t => unit,
    [@bs.optional]
    onPlaying: Event.Media.t => unit,
    [@bs.optional]
    onProgress: Event.Media.t => unit,
    [@bs.optional]
    onRateChange: Event.Media.t => unit,
    [@bs.optional]
    onSeeked: Event.Media.t => unit,
    [@bs.optional]
    onSeeking: Event.Media.t => unit,
    [@bs.optional]
    onStalled: Event.Media.t => unit,
    [@bs.optional]
    onSuspend: Event.Media.t => unit,
    [@bs.optional]
    onTimeUpdate: Event.Media.t => unit,
    [@bs.optional]
    onVolumeChange: Event.Media.t => unit,
    [@bs.optional]
    onWaiting: Event.Media.t => unit,
    /* Image events */
    [@bs.optional] onLoad: Event.Image.t => unit /* duplicate */, /*~onError: Event.Image.t => unit=?,*/
    /* Animation events */
    [@bs.optional]
    onAnimationStart: Event.Animation.t => unit,
    [@bs.optional]
    onAnimationEnd: Event.Animation.t => unit,
    [@bs.optional]
    onAnimationIteration: Event.Animation.t => unit,
    /* Transition events */
    [@bs.optional]
    onTransitionEnd: Event.Transition.t => unit,
    /* svg */
    [@bs.optional]
    accentHeight: string,
    [@bs.optional]
    accumulate: string,
    [@bs.optional]
    additive: string,
    [@bs.optional]
    alignmentBaseline: string,
    [@bs.optional]
    allowReorder: string,
    [@bs.optional]
    alphabetic: string,
    [@bs.optional]
    amplitude: string,
    [@bs.optional]
    arabicForm: string,
    [@bs.optional]
    ascent: string,
    [@bs.optional]
    attributeName: string,
    [@bs.optional]
    attributeType: string,
    [@bs.optional]
    autoReverse: string,
    [@bs.optional]
    azimuth: string,
    [@bs.optional]
    baseFrequency: string,
    [@bs.optional]
    baseProfile: string,
    [@bs.optional]
    baselineShift: string,
    [@bs.optional]
    bbox: string,
    [@bs.optional] [@bs.as "begin"]
    begin_: string, /* use this one. Previous one is deprecated */
    [@bs.optional]
    bias: string,
    [@bs.optional]
    by: string,
    [@bs.optional]
    calcMode: string,
    [@bs.optional]
    capHeight: string,
    [@bs.optional]
    clip: string,
    [@bs.optional]
    clipPath: string,
    [@bs.optional]
    clipPathUnits: string,
    [@bs.optional]
    clipRule: string,
    [@bs.optional]
    colorInterpolation: string,
    [@bs.optional]
    colorInterpolationFilters: string,
    [@bs.optional]
    colorProfile: string,
    [@bs.optional]
    colorRendering: string,
    [@bs.optional]
    contentScriptType: string,
    [@bs.optional]
    contentStyleType: string,
    [@bs.optional]
    cursor: string,
    [@bs.optional]
    cx: string,
    [@bs.optional]
    cy: string,
    [@bs.optional]
    d: string,
    [@bs.optional]
    decelerate: string,
    [@bs.optional]
    descent: string,
    [@bs.optional]
    diffuseConstant: string,
    [@bs.optional]
    direction: string,
    [@bs.optional]
    display: string,
    [@bs.optional]
    divisor: string,
    [@bs.optional]
    dominantBaseline: string,
    [@bs.optional]
    dur: string,
    [@bs.optional]
    dx: string,
    [@bs.optional]
    dy: string,
    [@bs.optional]
    edgeMode: string,
    [@bs.optional]
    elevation: string,
    [@bs.optional]
    enableBackground: string,
    [@bs.optional] [@bs.as "end"]
    end_: string, /* use this one. Previous one is deprecated */
    [@bs.optional]
    exponent: string,
    [@bs.optional]
    externalResourcesRequired: string,
    [@bs.optional]
    fill: string,
    [@bs.optional]
    fillOpacity: string,
    [@bs.optional]
    fillRule: string,
    [@bs.optional]
    filter: string,
    [@bs.optional]
    filterRes: string,
    [@bs.optional]
    filterUnits: string,
    [@bs.optional]
    floodColor: string,
    [@bs.optional]
    floodOpacity: string,
    [@bs.optional]
    focusable: string,
    [@bs.optional]
    fontFamily: string,
    [@bs.optional]
    fontSize: string,
    [@bs.optional]
    fontSizeAdjust: string,
    [@bs.optional]
    fontStretch: string,
    [@bs.optional]
    fontStyle: string,
    [@bs.optional]
    fontVariant: string,
    [@bs.optional]
    fontWeight: string,
    [@bs.optional]
    fomat: string,
    [@bs.optional]
    from: string,
    [@bs.optional]
    fx: string,
    [@bs.optional]
    fy: string,
    [@bs.optional]
    g1: string,
    [@bs.optional]
    g2: string,
    [@bs.optional]
    glyphName: string,
    [@bs.optional]
    glyphOrientationHorizontal: string,
    [@bs.optional]
    glyphOrientationVertical: string,
    [@bs.optional]
    glyphRef: string,
    [@bs.optional]
    gradientTransform: string,
    [@bs.optional]
    gradientUnits: string,
    [@bs.optional]
    hanging: string,
    [@bs.optional]
    horizAdvX: string,
    [@bs.optional]
    horizOriginX: string,
    [@bs.optional]
    ideographic: string,
    [@bs.optional]
    imageRendering: string,
    [@bs.optional] [@bs.as "in"]
    in_: string, /* use this one. Previous one is deprecated */
    [@bs.optional]
    in2: string,
    [@bs.optional]
    intercept: string,
    [@bs.optional]
    k: string,
    [@bs.optional]
    k1: string,
    [@bs.optional]
    k2: string,
    [@bs.optional]
    k3: string,
    [@bs.optional]
    k4: string,
    [@bs.optional]
    kernelMatrix: string,
    [@bs.optional]
    kernelUnitLength: string,
    [@bs.optional]
    kerning: string,
    [@bs.optional]
    keyPoints: string,
    [@bs.optional]
    keySplines: string,
    [@bs.optional]
    keyTimes: string,
    [@bs.optional]
    lengthAdjust: string,
    [@bs.optional]
    letterSpacing: string,
    [@bs.optional]
    lightingColor: string,
    [@bs.optional]
    limitingConeAngle: string,
    [@bs.optional]
    local: string,
    [@bs.optional]
    markerEnd: string,
    [@bs.optional]
    markerHeight: string,
    [@bs.optional]
    markerMid: string,
    [@bs.optional]
    markerStart: string,
    [@bs.optional]
    markerUnits: string,
    [@bs.optional]
    markerWidth: string,
    [@bs.optional]
    mask: string,
    [@bs.optional]
    maskContentUnits: string,
    [@bs.optional]
    maskUnits: string,
    [@bs.optional]
    mathematical: string,
    [@bs.optional]
    mode: string,
    [@bs.optional]
    numOctaves: string,
    [@bs.optional]
    offset: string,
    [@bs.optional]
    opacity: string,
    [@bs.optional]
    operator: string,
    [@bs.optional]
    order: string,
    [@bs.optional]
    orient: string,
    [@bs.optional]
    orientation: string,
    [@bs.optional]
    origin: string,
    [@bs.optional]
    overflow: string,
    [@bs.optional]
    overflowX: string,
    [@bs.optional]
    overflowY: string,
    [@bs.optional]
    overlinePosition: string,
    [@bs.optional]
    overlineThickness: string,
    [@bs.optional]
    paintOrder: string,
    [@bs.optional]
    panose1: string,
    [@bs.optional]
    pathLength: string,
    [@bs.optional]
    patternContentUnits: string,
    [@bs.optional]
    patternTransform: string,
    [@bs.optional]
    patternUnits: string,
    [@bs.optional]
    pointerEvents: string,
    [@bs.optional]
    points: string,
    [@bs.optional]
    pointsAtX: string,
    [@bs.optional]
    pointsAtY: string,
    [@bs.optional]
    pointsAtZ: string,
    [@bs.optional]
    preserveAlpha: string,
    [@bs.optional]
    preserveAspectRatio: string,
    [@bs.optional]
    primitiveUnits: string,
    [@bs.optional]
    r: string,
    [@bs.optional]
    radius: string,
    [@bs.optional]
    refX: string,
    [@bs.optional]
    refY: string,
    [@bs.optional]
    renderingIntent: string,
    [@bs.optional]
    repeatCount: string,
    [@bs.optional]
    repeatDur: string,
    [@bs.optional]
    requiredExtensions: string,
    [@bs.optional]
    requiredFeatures: string,
    [@bs.optional]
    restart: string,
    [@bs.optional]
    result: string,
    [@bs.optional]
    rotate: string,
    [@bs.optional]
    rx: string,
    [@bs.optional]
    ry: string,
    [@bs.optional]
    scale: string,
    [@bs.optional]
    seed: string,
    [@bs.optional]
    shapeRendering: string,
    [@bs.optional]
    slope: string,
    [@bs.optional]
    spacing: string,
    [@bs.optional]
    specularConstant: string,
    [@bs.optional]
    specularExponent: string,
    [@bs.optional]
    speed: string,
    [@bs.optional]
    spreadMethod: string,
    [@bs.optional]
    startOffset: string,
    [@bs.optional]
    stdDeviation: string,
    [@bs.optional]
    stemh: string,
    [@bs.optional]
    stemv: string,
    [@bs.optional]
    stitchTiles: string,
    [@bs.optional]
    stopColor: string,
    [@bs.optional]
    stopOpacity: string,
    [@bs.optional]
    strikethroughPosition: string,
    [@bs.optional]
    strikethroughThickness: string,
    [@bs.optional]
    string,
    [@bs.optional]
    stroke: string,
    [@bs.optional]
    strokeDasharray: string,
    [@bs.optional]
    strokeDashoffset: string,
    [@bs.optional]
    strokeLinecap: string,
    [@bs.optional]
    strokeLinejoin: string,
    [@bs.optional]
    strokeMiterlimit: string,
    [@bs.optional]
    strokeOpacity: string,
    [@bs.optional]
    strokeWidth: string,
    [@bs.optional]
    surfaceScale: string,
    [@bs.optional]
    systemLanguage: string,
    [@bs.optional]
    tableValues: string,
    [@bs.optional]
    targetX: string,
    [@bs.optional]
    targetY: string,
    [@bs.optional]
    textAnchor: string,
    [@bs.optional]
    textDecoration: string,
    [@bs.optional]
    textLength: string,
    [@bs.optional]
    textRendering: string,
    [@bs.optional] [@bs.as "to"]
    to_: string, /* use this one. Previous one is deprecated */
    [@bs.optional]
    transform: string,
    [@bs.optional]
    u1: string,
    [@bs.optional]
    u2: string,
    [@bs.optional]
    underlinePosition: string,
    [@bs.optional]
    underlineThickness: string,
    [@bs.optional]
    unicode: string,
    [@bs.optional]
    unicodeBidi: string,
    [@bs.optional]
    unicodeRange: string,
    [@bs.optional]
    unitsPerEm: string,
    [@bs.optional]
    vAlphabetic: string,
    [@bs.optional]
    vHanging: string,
    [@bs.optional]
    vIdeographic: string,
    [@bs.optional]
    vMathematical: string,
    [@bs.optional]
    values: string,
    [@bs.optional]
    vectorEffect: string,
    [@bs.optional]
    version: string,
    [@bs.optional]
    vertAdvX: string,
    [@bs.optional]
    vertAdvY: string,
    [@bs.optional]
    vertOriginX: string,
    [@bs.optional]
    vertOriginY: string,
    [@bs.optional]
    viewBox: string,
    [@bs.optional]
    viewTarget: string,
    [@bs.optional]
    visibility: string,
    /*width::string? =>*/
    [@bs.optional]
    widths: string,
    [@bs.optional]
    wordSpacing: string,
    [@bs.optional]
    writingMode: string,
    [@bs.optional]
    x: string,
    [@bs.optional]
    x1: string,
    [@bs.optional]
    x2: string,
    [@bs.optional]
    xChannelSelector: string,
    [@bs.optional]
    xHeight: string,
    [@bs.optional]
    xlinkActuate: string,
    [@bs.optional]
    xlinkArcrole: string,
    [@bs.optional]
    xlinkHref: string,
    [@bs.optional]
    xlinkRole: string,
    [@bs.optional]
    xlinkShow: string,
    [@bs.optional]
    xlinkTitle: string,
    [@bs.optional]
    xlinkType: string,
    [@bs.optional]
    xmlns: string,
    [@bs.optional]
    xmlnsXlink: string,
    [@bs.optional]
    xmlBase: string,
    [@bs.optional]
    xmlLang: string,
    [@bs.optional]
    xmlSpace: string,
    [@bs.optional]
    y: string,
    [@bs.optional]
    y1: string,
    [@bs.optional]
    y2: string,
    [@bs.optional]
    yChannelSelector: string,
    [@bs.optional]
    z: string,
    [@bs.optional]
    zoomAndPan: string,
    /* RDFa */
    [@bs.optional]
    about: string,
    [@bs.optional]
    datatype: string,
    [@bs.optional]
    inlist: string,
    [@bs.optional]
    prefix: string,
    [@bs.optional]
    property: string,
    [@bs.optional]
    resource: string,
    [@bs.optional]
    typeof: string,
    [@bs.optional]
    vocab: string,
    /* react-specific */
    /*[@bs.optional] dangerouslySetInnerHTML: {. "__html": string},*/
    [@bs.optional]
    suppressContentEditableWarning: bool,
  };

  let make = t;
};

let create =
    (
      tag: string,
      ~key: option(string)=?,
      ~ref_: option(domRef)=?,
      ~ariaDetails: option(string)=?,
      ~ariaDisabled: option(bool)=?,
      ~ariaHidden: option(bool)=?,
      ~ariaKeyshortcuts: option(string)=?,
      ~ariaLabel: option(string)=?,
      ~ariaRoledescription: option(string)=?,
      ~ariaExpanded: option(bool)=?,
      ~ariaLevel: option(int)=?,
      ~ariaModal: option(bool)=?,
      ~ariaMultiline: option(bool)=?,
      ~ariaMultiselectable: option(bool)=?,
      ~ariaPlaceholder: option(string)=?,
      ~ariaReadonly: option(bool)=?,
      ~ariaRequired: option(bool)=?,
      ~ariaSelected: option(bool)=?,
      ~ariaSort: option(string)=?,
      ~ariaValuemax: option(float)=?,
      ~ariaValuemin: option(float)=?,
      ~ariaValuenow: option(float)=?,
      ~ariaValuetext: option(string)=?,
      ~ariaAtomic: option(bool)=?,
      ~ariaBusy: option(bool)=?,
      ~ariaRelevant: option(string)=?,
      ~ariaGrabbed: option(bool)=?,
      ~ariaActivedescendant: option(string)=?,
      ~ariaColcount: option(int)=?,
      ~ariaColindex: option(int)=?,
      ~ariaColspan: option(int)=?,
      ~ariaControls: option(string)=?,
      ~ariaDescribedby: option(string)=?,
      ~ariaErrormessage: option(string)=?,
      ~ariaFlowto: option(string)=?,
      ~ariaLabelledby: option(string)=?,
      ~ariaOwns: option(string)=?,
      ~ariaPosinset: option(int)=?,
      ~ariaRowcount: option(int)=?,
      ~ariaRowindex: option(int)=?,
      ~ariaRowspan: option(int)=?,
      ~ariaSetsize: option(int)=?,
      ~defaultChecked: option(bool)=?,
      ~defaultValue: option(string)=?,
      ~accessKey: option(string)=?,
      ~className: option(string)=?,
      ~contentEditable: option(bool)=?,
      ~contextMenu: option(string)=?,
      ~dir: option(string)=?,
      ~draggable: option(bool)=?,
      ~hidden: option(bool)=?,
      ~id: option(string)=?,
      ~lang: option(string)=?,
      ~role: option(string)=?,
      ~style: option(style)=?,
      ~spellCheck: option(bool)=?,
      ~tabIndex: option(int)=?,
      ~title: option(string)=?,
      ~itemID: option(string)=?,
      ~itemProp: option(string)=?,
      ~itemRef: option(string)=?,
      ~itemScope: option(bool)=?,
      ~itemType: option(string)=?,
      ~accept: option(string)=?,
      ~acceptCharset: option(string)=?,
      ~action: option(string)=?,
      ~allowFullScreen: option(bool)=?,
      ~alt: option(string)=?,
      ~async: option(bool)=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~autoPlay: option(bool)=?,
      ~challenge: option(string)=?,
      ~charSet: option(string)=?,
      ~checked: option(bool)=?,
      ~cite: option(string)=?,
      ~crossOrigin: option(string)=?,
      ~cols: option(int)=?,
      ~colSpan: option(int)=?,
      ~content: option(string)=?,
      ~controls: option(bool)=?,
      ~coords: option(string)=?,
      ~data: option(string)=?,
      ~dateTime: option(string)=?,
      ~default: option(bool)=?,
      ~defer: option(bool)=?,
      ~disabled: option(bool)=?,
      ~download: option(string)=?,
      ~encType: option(string)=?,
      ~form: option(string)=?,
      ~formAction: option(string)=?,
      ~formTarget: option(string)=?,
      ~formMethod: option(string)=?,
      ~headers: option(string)=?,
      ~height: option(string)=?,
      ~high: option(int)=?,
      ~href: option(string)=?,
      ~hrefLang: option(string)=?,
      ~htmlFor: option(string)=?,
      ~httpEquiv: option(string)=?,
      ~icon: option(string)=?,
      ~inputMode: option(string)=?,
      ~integrity: option(string)=?,
      ~keyType: option(string)=?,
      ~kind: option(string)=?,
      ~label: option(string)=?,
      ~list: option(string)=?,
      ~loop: option(bool)=?,
      ~low: option(int)=?,
      ~manifest: option(string)=?,
      ~max: option(string)=?,
      ~maxLength: option(int)=?,
      ~media: option(string)=?,
      ~mediaGroup: option(string)=?,
      ~method: option(string)=?,
      ~min: option(int)=?,
      ~minLength: option(int)=?,
      ~multiple: option(bool)=?,
      ~muted: option(bool)=?,
      ~name: option(string)=?,
      ~nonce: option(string)=?,
      ~noValidate: option(bool)=?,
      ~open_: option(bool)=?,
      ~optimum: option(int)=?,
      ~pattern: option(string)=?,
      ~placeholder: option(string)=?,
      ~poster: option(string)=?,
      ~preload: option(string)=?,
      ~radioGroup: option(string)=?,
      ~readOnly: option(bool)=?,
      ~rel: option(string)=?,
      ~required: option(bool)=?,
      ~reversed: option(bool)=?,
      ~rows: option(int)=?,
      ~rowSpan: option(int)=?,
      ~sandbox: option(string)=?,
      ~scope: option(string)=?,
      ~scoped: option(bool)=?,
      ~scrolling: option(string)=?,
      ~selected: option(bool)=?,
      ~shape: option(string)=?,
      ~size: option(int)=?,
      ~sizes: option(string)=?,
      ~span: option(int)=?,
      ~src: option(string)=?,
      ~srcDoc: option(string)=?,
      ~srcLang: option(string)=?,
      ~srcSet: option(string)=?,
      ~start: option(int)=?,
      ~step: option(float)=?,
      ~summary: option(string)=?,
      ~target: option(string)=?,
      ~type_: option(string)=?,
      ~useMap: option(string)=?,
      ~value: option(string)=?,
      ~width: option(string)=?,
      ~wrap: option(string)=?,
      ~onCopy: option(Event.Clipboard.t => unit)=?,
      ~onCut: option(Event.Clipboard.t => unit)=?,
      ~onPaste: option(Event.Clipboard.t => unit)=?,
      ~onCompositionEnd: option(Event.Composition.t => unit)=?,
      ~onCompositionStart: option(Event.Composition.t => unit)=?,
      ~onCompositionUpdate: option(Event.Composition.t => unit)=?,
      ~onKeyDown: option(Event.Keyboard.t => unit)=?,
      ~onKeyPress: option(Event.Keyboard.t => unit)=?,
      ~onKeyUp: option(Event.Keyboard.t => unit)=?,
      ~onFocus: option(Event.Focus.t => unit)=?,
      ~onBlur: option(Event.Focus.t => unit)=?,
      ~onChange: option(Event.Form.t => unit)=?,
      ~onInput: option(Event.Form.t => unit)=?,
      ~onSubmit: option(Event.Form.t => unit)=?,
      ~onClick: option(Event.Mouse.t => unit)=?,
      ~onContextMenu: option(Event.Mouse.t => unit)=?,
      ~onDoubleClick: option(Event.Mouse.t => unit)=?,
      ~onDrag: option(Event.Mouse.t => unit)=?,
      ~onDragEnd: option(Event.Mouse.t => unit)=?,
      ~onDragEnter: option(Event.Mouse.t => unit)=?,
      ~onDragExit: option(Event.Mouse.t => unit)=?,
      ~onDragLeave: option(Event.Mouse.t => unit)=?,
      ~onDragOver: option(Event.Mouse.t => unit)=?,
      ~onDragStart: option(Event.Mouse.t => unit)=?,
      ~onDrop: option(Event.Mouse.t => unit)=?,
      ~onMouseDown: option(Event.Mouse.t => unit)=?,
      ~onMouseEnter: option(Event.Mouse.t => unit)=?,
      ~onMouseLeave: option(Event.Mouse.t => unit)=?,
      ~onMouseMove: option(Event.Mouse.t => unit)=?,
      ~onMouseOut: option(Event.Mouse.t => unit)=?,
      ~onMouseOver: option(Event.Mouse.t => unit)=?,
      ~onMouseUp: option(Event.Mouse.t => unit)=?,
      ~onSelect: option(Event.Selection.t => unit)=?,
      ~onTouchCancel: option(Event.Touch.t => unit)=?,
      ~onTouchEnd: option(Event.Touch.t => unit)=?,
      ~onTouchMove: option(Event.Touch.t => unit)=?,
      ~onTouchStart: option(Event.Touch.t => unit)=?,
      ~onScroll: option(Event.UI.t => unit)=?,
      ~onWheel: option(Event.Wheel.t => unit)=?,
      ~onAbort: option(Event.Media.t => unit)=?,
      ~onCanPlay: option(Event.Media.t => unit)=?,
      ~onCanPlayThrough: option(Event.Media.t => unit)=?,
      ~onDurationChange: option(Event.Media.t => unit)=?,
      ~onEmptied: option(Event.Media.t => unit)=?,
      ~onEncrypetd: option(Event.Media.t => unit)=?,
      ~onEnded: option(Event.Media.t => unit)=?,
      ~onError: option(Event.Media.t => unit)=?,
      ~onLoadedData: option(Event.Media.t => unit)=?,
      ~onLoadedMetadata: option(Event.Media.t => unit)=?,
      ~onLoadStart: option(Event.Media.t => unit)=?,
      ~onPause: option(Event.Media.t => unit)=?,
      ~onPlay: option(Event.Media.t => unit)=?,
      ~onPlaying: option(Event.Media.t => unit)=?,
      ~onProgress: option(Event.Media.t => unit)=?,
      ~onRateChange: option(Event.Media.t => unit)=?,
      ~onSeeked: option(Event.Media.t => unit)=?,
      ~onSeeking: option(Event.Media.t => unit)=?,
      ~onStalled: option(Event.Media.t => unit)=?,
      ~onSuspend: option(Event.Media.t => unit)=?,
      ~onTimeUpdate: option(Event.Media.t => unit)=?,
      ~onVolumeChange: option(Event.Media.t => unit)=?,
      ~onWaiting: option(Event.Media.t => unit)=?,
      ~onLoad: option(Event.Image.t => unit)=?,
      ~onAnimationStart: option(Event.Animation.t => unit)=?,
      ~onAnimationEnd: option(Event.Animation.t => unit)=?,
      ~onAnimationIteration: option(Event.Animation.t => unit)=?,
      ~onTransitionEnd: option(Event.Transition.t => unit)=?,
      ~accentHeight: option(string)=?,
      ~accumulate: option(string)=?,
      ~additive: option(string)=?,
      ~alignmentBaseline: option(string)=?,
      ~allowReorder: option(string)=?,
      ~alphabetic: option(string)=?,
      ~amplitude: option(string)=?,
      ~arabicForm: option(string)=?,
      ~ascent: option(string)=?,
      ~attributeName: option(string)=?,
      ~attributeType: option(string)=?,
      ~autoReverse: option(string)=?,
      ~azimuth: option(string)=?,
      ~baseFrequency: option(string)=?,
      ~baseProfile: option(string)=?,
      ~baselineShift: option(string)=?,
      ~bbox: option(string)=?,
      ~begin_: option(string)=?,
      ~bias: option(string)=?,
      ~by: option(string)=?,
      ~calcMode: option(string)=?,
      ~capHeight: option(string)=?,
      ~clip: option(string)=?,
      ~clipPath: option(string)=?,
      ~clipPathUnits: option(string)=?,
      ~clipRule: option(string)=?,
      ~colorInterpolation: option(string)=?,
      ~colorInterpolationFilters: option(string)=?,
      ~colorProfile: option(string)=?,
      ~colorRendering: option(string)=?,
      ~contentScriptType: option(string)=?,
      ~contentStyleType: option(string)=?,
      ~cursor: option(string)=?,
      ~cx: option(string)=?,
      ~cy: option(string)=?,
      ~d: option(string)=?,
      ~decelerate: option(string)=?,
      ~descent: option(string)=?,
      ~diffuseConstant: option(string)=?,
      ~direction: option(string)=?,
      ~display: option(string)=?,
      ~divisor: option(string)=?,
      ~dominantBaseline: option(string)=?,
      ~dur: option(string)=?,
      ~dx: option(string)=?,
      ~dy: option(string)=?,
      ~edgeMode: option(string)=?,
      ~elevation: option(string)=?,
      ~enableBackground: option(string)=?,
      ~end_: option(string)=?,
      ~exponent: option(string)=?,
      ~externalResourcesRequired: option(string)=?,
      ~fill: option(string)=?,
      ~fillOpacity: option(string)=?,
      ~fillRule: option(string)=?,
      ~filter: option(string)=?,
      ~filterRes: option(string)=?,
      ~filterUnits: option(string)=?,
      ~floodColor: option(string)=?,
      ~floodOpacity: option(string)=?,
      ~focusable: option(string)=?,
      ~fontFamily: option(string)=?,
      ~fontSize: option(string)=?,
      ~fontSizeAdjust: option(string)=?,
      ~fontStretch: option(string)=?,
      ~fontStyle: option(string)=?,
      ~fontVariant: option(string)=?,
      ~fontWeight: option(string)=?,
      ~fomat: option(string)=?,
      ~from: option(string)=?,
      ~fx: option(string)=?,
      ~fy: option(string)=?,
      ~g1: option(string)=?,
      ~g2: option(string)=?,
      ~glyphName: option(string)=?,
      ~glyphOrientationHorizontal: option(string)=?,
      ~glyphOrientationVertical: option(string)=?,
      ~glyphRef: option(string)=?,
      ~gradientTransform: option(string)=?,
      ~gradientUnits: option(string)=?,
      ~hanging: option(string)=?,
      ~horizAdvX: option(string)=?,
      ~horizOriginX: option(string)=?,
      ~ideographic: option(string)=?,
      ~imageRendering: option(string)=?,
      ~in_: option(string)=?,
      ~in2: option(string)=?,
      ~intercept: option(string)=?,
      ~k: option(string)=?,
      ~k1: option(string)=?,
      ~k2: option(string)=?,
      ~k3: option(string)=?,
      ~k4: option(string)=?,
      ~kernelMatrix: option(string)=?,
      ~kernelUnitLength: option(string)=?,
      ~kerning: option(string)=?,
      ~keyPoints: option(string)=?,
      ~keySplines: option(string)=?,
      ~keyTimes: option(string)=?,
      ~lengthAdjust: option(string)=?,
      ~letterSpacing: option(string)=?,
      ~lightingColor: option(string)=?,
      ~limitingConeAngle: option(string)=?,
      ~local: option(string)=?,
      ~markerEnd: option(string)=?,
      ~markerHeight: option(string)=?,
      ~markerMid: option(string)=?,
      ~markerStart: option(string)=?,
      ~markerUnits: option(string)=?,
      ~markerWidth: option(string)=?,
      ~mask: option(string)=?,
      ~maskContentUnits: option(string)=?,
      ~maskUnits: option(string)=?,
      ~mathematical: option(string)=?,
      ~mode: option(string)=?,
      ~numOctaves: option(string)=?,
      ~offset: option(string)=?,
      ~opacity: option(string)=?,
      ~operator: option(string)=?,
      ~order: option(string)=?,
      ~orient: option(string)=?,
      ~orientation: option(string)=?,
      ~origin: option(string)=?,
      ~overflow: option(string)=?,
      ~overflowX: option(string)=?,
      ~overflowY: option(string)=?,
      ~overlinePosition: option(string)=?,
      ~overlineThickness: option(string)=?,
      ~paintOrder: option(string)=?,
      ~panose1: option(string)=?,
      ~pathLength: option(string)=?,
      ~patternContentUnits: option(string)=?,
      ~patternTransform: option(string)=?,
      ~patternUnits: option(string)=?,
      ~pointerEvents: option(string)=?,
      ~points: option(string)=?,
      ~pointsAtX: option(string)=?,
      ~pointsAtY: option(string)=?,
      ~pointsAtZ: option(string)=?,
      ~preserveAlpha: option(string)=?,
      ~preserveAspectRatio: option(string)=?,
      ~primitiveUnits: option(string)=?,
      ~r: option(string)=?,
      ~radius: option(string)=?,
      ~refX: option(string)=?,
      ~refY: option(string)=?,
      ~renderingIntent: option(string)=?,
      ~repeatCount: option(string)=?,
      ~repeatDur: option(string)=?,
      ~requiredExtensions: option(string)=?,
      ~requiredFeatures: option(string)=?,
      ~restart: option(string)=?,
      ~result: option(string)=?,
      ~rotate: option(string)=?,
      ~rx: option(string)=?,
      ~ry: option(string)=?,
      ~scale: option(string)=?,
      ~seed: option(string)=?,
      ~shapeRendering: option(string)=?,
      ~slope: option(string)=?,
      ~spacing: option(string)=?,
      ~specularConstant: option(string)=?,
      ~specularExponent: option(string)=?,
      ~speed: option(string)=?,
      ~spreadMethod: option(string)=?,
      ~startOffset: option(string)=?,
      ~stdDeviation: option(string)=?,
      ~stemh: option(string)=?,
      ~stemv: option(string)=?,
      ~stitchTiles: option(string)=?,
      ~stopColor: option(string)=?,
      ~stopOpacity: option(string)=?,
      ~strikethroughPosition: option(string)=?,
      ~strikethroughThickness: option(string)=?,
      ~string: option(string)=?,
      ~stroke: option(string)=?,
      ~strokeDasharray: option(string)=?,
      ~strokeDashoffset: option(string)=?,
      ~strokeLinecap: option(string)=?,
      ~strokeLinejoin: option(string)=?,
      ~strokeMiterlimit: option(string)=?,
      ~strokeOpacity: option(string)=?,
      ~strokeWidth: option(string)=?,
      ~surfaceScale: option(string)=?,
      ~systemLanguage: option(string)=?,
      ~tableValues: option(string)=?,
      ~targetX: option(string)=?,
      ~targetY: option(string)=?,
      ~textAnchor: option(string)=?,
      ~textDecoration: option(string)=?,
      ~textLength: option(string)=?,
      ~textRendering: option(string)=?,
      ~to_: option(string)=?,
      ~transform: option(string)=?,
      ~u1: option(string)=?,
      ~u2: option(string)=?,
      ~underlinePosition: option(string)=?,
      ~underlineThickness: option(string)=?,
      ~unicode: option(string)=?,
      ~unicodeBidi: option(string)=?,
      ~unicodeRange: option(string)=?,
      ~unitsPerEm: option(string)=?,
      ~vAlphabetic: option(string)=?,
      ~vHanging: option(string)=?,
      ~vIdeographic: option(string)=?,
      ~vMathematical: option(string)=?,
      ~values: option(string)=?,
      ~vectorEffect: option(string)=?,
      ~version: option(string)=?,
      ~vertAdvX: option(string)=?,
      ~vertAdvY: option(string)=?,
      ~vertOriginX: option(string)=?,
      ~vertOriginY: option(string)=?,
      ~viewBox: option(string)=?,
      ~viewTarget: option(string)=?,
      ~visibility: option(string)=?,
      ~widths: option(string)=?,
      ~wordSpacing: option(string)=?,
      ~writingMode: option(string)=?,
      ~x: option(string)=?,
      ~x1: option(string)=?,
      ~x2: option(string)=?,
      ~xChannelSelector: option(string)=?,
      ~xHeight: option(string)=?,
      ~xlinkActuate: option(string)=?,
      ~xlinkArcrole: option(string)=?,
      ~xlinkHref: option(string)=?,
      ~xlinkRole: option(string)=?,
      ~xlinkShow: option(string)=?,
      ~xlinkTitle: option(string)=?,
      ~xlinkType: option(string)=?,
      ~xmlns: option(string)=?,
      ~xmlnsXlink: option(string)=?,
      ~xmlBase: option(string)=?,
      ~xmlLang: option(string)=?,
      ~xmlSpace: option(string)=?,
      ~y: option(string)=?,
      ~y1: option(string)=?,
      ~y2: option(string)=?,
      ~yChannelSelector: option(string)=?,
      ~z: option(string)=?,
      ~zoomAndPan: option(string)=?,
      ~about: option(string)=?,
      ~datatype: option(string)=?,
      ~inlist: option(string)=?,
      ~prefix: option(string)=?,
      ~property: option(string)=?,
      ~resource: option(string)=?,
      ~typeof: option(string)=?,
      ~vocab: option(string)=?,
      ~suppressContentEditableWarning: option(bool)=?,
      children: list(t),
    ) => {
  let props =
    Props.make(
      ~ref_?,
      ~key?,
      ~ariaDetails?,
      ~ariaDisabled?,
      ~ariaHidden?,
      ~ariaKeyshortcuts?,
      ~ariaLabel?,
      ~ariaRoledescription?,
      ~ariaExpanded?,
      ~ariaLevel?,
      ~ariaModal?,
      ~ariaMultiline?,
      ~ariaMultiselectable?,
      ~ariaPlaceholder?,
      ~ariaReadonly?,
      ~ariaRequired?,
      ~ariaSelected?,
      ~ariaSort?,
      ~ariaValuemax?,
      ~ariaValuemin?,
      ~ariaValuenow?,
      ~ariaValuetext?,
      ~ariaAtomic?,
      ~ariaBusy?,
      ~ariaRelevant?,
      ~ariaGrabbed?,
      ~ariaActivedescendant?,
      ~ariaColcount?,
      ~ariaColindex?,
      ~ariaColspan?,
      ~ariaControls?,
      ~ariaDescribedby?,
      ~ariaErrormessage?,
      ~ariaFlowto?,
      ~ariaLabelledby?,
      ~ariaOwns?,
      ~ariaPosinset?,
      ~ariaRowcount?,
      ~ariaRowindex?,
      ~ariaRowspan?,
      ~ariaSetsize?,
      ~defaultChecked?,
      ~defaultValue?,
      ~accessKey?,
      ~className?,
      ~contentEditable?,
      ~contextMenu?,
      ~dir?,
      ~draggable?,
      ~hidden?,
      ~id?,
      ~lang?,
      ~role?,
      ~style?,
      ~spellCheck?,
      ~tabIndex?,
      ~title?,
      ~itemID?,
      ~itemProp?,
      ~itemRef?,
      ~itemScope?,
      ~itemType?,
      ~accept?,
      ~acceptCharset?,
      ~action?,
      ~allowFullScreen?,
      ~alt?,
      ~async?,
      ~autoComplete?,
      ~autoFocus?,
      ~autoPlay?,
      ~challenge?,
      ~charSet?,
      ~checked?,
      ~cite?,
      ~crossOrigin?,
      ~cols?,
      ~colSpan?,
      ~content?,
      ~controls?,
      ~coords?,
      ~data?,
      ~dateTime?,
      ~default?,
      ~defer?,
      ~disabled?,
      ~download?,
      ~encType?,
      ~form?,
      ~formAction?,
      ~formTarget?,
      ~formMethod?,
      ~headers?,
      ~height?,
      ~high?,
      ~href?,
      ~hrefLang?,
      ~htmlFor?,
      ~httpEquiv?,
      ~icon?,
      ~inputMode?,
      ~integrity?,
      ~keyType?,
      ~kind?,
      ~label?,
      ~list?,
      ~loop?,
      ~low?,
      ~manifest?,
      ~max?,
      ~maxLength?,
      ~media?,
      ~mediaGroup?,
      ~method?,
      ~min?,
      ~minLength?,
      ~multiple?,
      ~muted?,
      ~name?,
      ~nonce?,
      ~noValidate?,
      ~open_?,
      ~optimum?,
      ~pattern?,
      ~placeholder?,
      ~poster?,
      ~preload?,
      ~radioGroup?,
      ~readOnly?,
      ~rel?,
      ~required?,
      ~reversed?,
      ~rows?,
      ~rowSpan?,
      ~sandbox?,
      ~scope?,
      ~scoped?,
      ~scrolling?,
      ~selected?,
      ~shape?,
      ~size?,
      ~sizes?,
      ~span?,
      ~src?,
      ~srcDoc?,
      ~srcLang?,
      ~srcSet?,
      ~start?,
      ~step?,
      ~summary?,
      ~target?,
      ~type_?,
      ~useMap?,
      ~value?,
      ~width?,
      ~wrap?,
      ~onCopy?,
      ~onCut?,
      ~onPaste?,
      ~onCompositionEnd?,
      ~onCompositionStart?,
      ~onCompositionUpdate?,
      ~onKeyDown?,
      ~onKeyPress?,
      ~onKeyUp?,
      ~onFocus?,
      ~onBlur?,
      ~onChange?,
      ~onInput?,
      ~onSubmit?,
      ~onClick?,
      ~onContextMenu?,
      ~onDoubleClick?,
      ~onDrag?,
      ~onDragEnd?,
      ~onDragEnter?,
      ~onDragExit?,
      ~onDragLeave?,
      ~onDragOver?,
      ~onDragStart?,
      ~onDrop?,
      ~onMouseDown?,
      ~onMouseEnter?,
      ~onMouseLeave?,
      ~onMouseMove?,
      ~onMouseOut?,
      ~onMouseOver?,
      ~onMouseUp?,
      ~onSelect?,
      ~onTouchCancel?,
      ~onTouchEnd?,
      ~onTouchMove?,
      ~onTouchStart?,
      ~onScroll?,
      ~onWheel?,
      ~onAbort?,
      ~onCanPlay?,
      ~onCanPlayThrough?,
      ~onDurationChange?,
      ~onEmptied?,
      ~onEncrypetd?,
      ~onEnded?,
      ~onError?,
      ~onLoadedData?,
      ~onLoadedMetadata?,
      ~onLoadStart?,
      ~onPause?,
      ~onPlay?,
      ~onPlaying?,
      ~onProgress?,
      ~onRateChange?,
      ~onSeeked?,
      ~onSeeking?,
      ~onStalled?,
      ~onSuspend?,
      ~onTimeUpdate?,
      ~onVolumeChange?,
      ~onWaiting?,
      ~onLoad?,
      ~onAnimationStart?,
      ~onAnimationEnd?,
      ~onAnimationIteration?,
      ~onTransitionEnd?,
      ~accentHeight?,
      ~accumulate?,
      ~additive?,
      ~alignmentBaseline?,
      ~allowReorder?,
      ~alphabetic?,
      ~amplitude?,
      ~arabicForm?,
      ~ascent?,
      ~attributeName?,
      ~attributeType?,
      ~autoReverse?,
      ~azimuth?,
      ~baseFrequency?,
      ~baseProfile?,
      ~baselineShift?,
      ~bbox?,
      ~begin_?,
      ~bias?,
      ~by?,
      ~calcMode?,
      ~capHeight?,
      ~clip?,
      ~clipPath?,
      ~clipPathUnits?,
      ~clipRule?,
      ~colorInterpolation?,
      ~colorInterpolationFilters?,
      ~colorProfile?,
      ~colorRendering?,
      ~contentScriptType?,
      ~contentStyleType?,
      ~cursor?,
      ~cx?,
      ~cy?,
      ~d?,
      ~decelerate?,
      ~descent?,
      ~diffuseConstant?,
      ~direction?,
      ~display?,
      ~divisor?,
      ~dominantBaseline?,
      ~dur?,
      ~dx?,
      ~dy?,
      ~edgeMode?,
      ~elevation?,
      ~enableBackground?,
      ~end_?,
      ~exponent?,
      ~externalResourcesRequired?,
      ~fill?,
      ~fillOpacity?,
      ~fillRule?,
      ~filter?,
      ~filterRes?,
      ~filterUnits?,
      ~floodColor?,
      ~floodOpacity?,
      ~focusable?,
      ~fontFamily?,
      ~fontSize?,
      ~fontSizeAdjust?,
      ~fontStretch?,
      ~fontStyle?,
      ~fontVariant?,
      ~fontWeight?,
      ~fomat?,
      ~from?,
      ~fx?,
      ~fy?,
      ~g1?,
      ~g2?,
      ~glyphName?,
      ~glyphOrientationHorizontal?,
      ~glyphOrientationVertical?,
      ~glyphRef?,
      ~gradientTransform?,
      ~gradientUnits?,
      ~hanging?,
      ~horizAdvX?,
      ~horizOriginX?,
      ~ideographic?,
      ~imageRendering?,
      ~in_?,
      ~in2?,
      ~intercept?,
      ~k?,
      ~k1?,
      ~k2?,
      ~k3?,
      ~k4?,
      ~kernelMatrix?,
      ~kernelUnitLength?,
      ~kerning?,
      ~keyPoints?,
      ~keySplines?,
      ~keyTimes?,
      ~lengthAdjust?,
      ~letterSpacing?,
      ~lightingColor?,
      ~limitingConeAngle?,
      ~local?,
      ~markerEnd?,
      ~markerHeight?,
      ~markerMid?,
      ~markerStart?,
      ~markerUnits?,
      ~markerWidth?,
      ~mask?,
      ~maskContentUnits?,
      ~maskUnits?,
      ~mathematical?,
      ~mode?,
      ~numOctaves?,
      ~offset?,
      ~opacity?,
      ~operator?,
      ~order?,
      ~orient?,
      ~orientation?,
      ~origin?,
      ~overflow?,
      ~overflowX?,
      ~overflowY?,
      ~overlinePosition?,
      ~overlineThickness?,
      ~paintOrder?,
      ~panose1?,
      ~pathLength?,
      ~patternContentUnits?,
      ~patternTransform?,
      ~patternUnits?,
      ~pointerEvents?,
      ~points?,
      ~pointsAtX?,
      ~pointsAtY?,
      ~pointsAtZ?,
      ~preserveAlpha?,
      ~preserveAspectRatio?,
      ~primitiveUnits?,
      ~r?,
      ~radius?,
      ~refX?,
      ~refY?,
      ~renderingIntent?,
      ~repeatCount?,
      ~repeatDur?,
      ~requiredExtensions?,
      ~requiredFeatures?,
      ~restart?,
      ~result?,
      ~rotate?,
      ~rx?,
      ~ry?,
      ~scale?,
      ~seed?,
      ~shapeRendering?,
      ~slope?,
      ~spacing?,
      ~specularConstant?,
      ~specularExponent?,
      ~speed?,
      ~spreadMethod?,
      ~startOffset?,
      ~stdDeviation?,
      ~stemh?,
      ~stemv?,
      ~stitchTiles?,
      ~stopColor?,
      ~stopOpacity?,
      ~strikethroughPosition?,
      ~strikethroughThickness?,
      ~string?,
      ~stroke?,
      ~strokeDasharray?,
      ~strokeDashoffset?,
      ~strokeLinecap?,
      ~strokeLinejoin?,
      ~strokeMiterlimit?,
      ~strokeOpacity?,
      ~strokeWidth?,
      ~surfaceScale?,
      ~systemLanguage?,
      ~tableValues?,
      ~targetX?,
      ~targetY?,
      ~textAnchor?,
      ~textDecoration?,
      ~textLength?,
      ~textRendering?,
      ~to_?,
      ~transform?,
      ~u1?,
      ~u2?,
      ~underlinePosition?,
      ~underlineThickness?,
      ~unicode?,
      ~unicodeBidi?,
      ~unicodeRange?,
      ~unitsPerEm?,
      ~vAlphabetic?,
      ~vHanging?,
      ~vIdeographic?,
      ~vMathematical?,
      ~values?,
      ~vectorEffect?,
      ~version?,
      ~vertAdvX?,
      ~vertAdvY?,
      ~vertOriginX?,
      ~vertOriginY?,
      ~viewBox?,
      ~viewTarget?,
      ~visibility?,
      ~widths?,
      ~wordSpacing?,
      ~writingMode?,
      ~x?,
      ~x1?,
      ~x2?,
      ~xChannelSelector?,
      ~xHeight?,
      ~xlinkActuate?,
      ~xlinkArcrole?,
      ~xlinkHref?,
      ~xlinkRole?,
      ~xlinkShow?,
      ~xlinkTitle?,
      ~xlinkType?,
      ~xmlns?,
      ~xmlnsXlink?,
      ~xmlBase?,
      ~xmlLang?,
      ~xmlSpace?,
      ~y?,
      ~y1?,
      ~y2?,
      ~yChannelSelector?,
      ~z?,
      ~zoomAndPan?,
      ~about?,
      ~datatype?,
      ~inlist?,
      ~prefix?,
      ~property?,
      ~resource?,
      ~typeof?,
      ~vocab?,
      ~suppressContentEditableWarning?,
      (),
    );

  rawCreateElement(tag, props, Array.of_list(children));
};

let a = create("a");
let abbr = create("abbr");
let address = create("address");
let area = create("area");
let article = create("article");
let aside = create("aside");
let audio = create("audio");
let b = create("b");
let base = create("base");
let bdi = create("bdi");
let bdo = create("bdo");
let big = create("big");
let blockquote = create("blockquote");
let body = create("body");
let br = create("br");
let button = create("button");
let canvas = create("canvas");
let caption = create("caption");
let cite = create("cite");
let code = create("code");
let col = create("col");
let colgroup = create("colgroup");
let data = create("data");
let datalist = create("datalist");
let dd = create("dd");
let del = create("del");
let details = create("details");
let dfn = create("dfn");
let dialog = create("dialog");
let div = create("div");
let dl = create("dl");
let dt = create("dt");
let em = create("em");
let embed = create("embed");
let fieldset = create("fieldset");
let figcaption = create("figcaption");
let figure = create("figure");
let footer = create("footer");
let form = create("form");
let h1 = create("h1");
let h2 = create("h2");
let h3 = create("h3");
let h4 = create("h4");
let h5 = create("h5");
let h6 = create("h6");
let head = create("head");
let header = create("header");
let hgroup = create("hgroup");
let hr = create("hr");
let html = create("html");
let i = create("i");
let iframe = create("iframe");
let img = create("img");
let input = create("input");
let input_ = create("input"); /* Alias to prevent hiding ocaml "input" function*/
let ins = create("ins");
let kbd = create("kbd");
let keygen = create("keygen");
let label = create("label");
let legend = create("legend");
let li = create("li");
let link = create("link");
let main = create("main");
let map = create("map");
let mark = create("mark");
let menu = create("menu");
let menuitem = create("menuitem");
let meta = create("meta");
let meter = create("meter");
let nav = create("nav");
let noscript = create("noscript");
let object_ = create("object");
let ol = create("ol");
let optgroup = create("optgroup");
let option_ = create("option");
let output = create("output");
let p = create("p");
let param = create("param");
let picture = create("picture");
let pre = create("pre");
let progress = create("progress");
let q = create("q");
let rp = create("rp");
let rt = create("rt");
let ruby = create("ruby");
let s = create("s");
let samp = create("samp");
let script = create("script");
let section = create("section");
let select = create("select");
let small = create("small");
let source = create("source");
let span = create("span");
let strong = create("strong");
let style = create("style");
let sub = create("sub");
let summary = create("summary");
let sup = create("sup");
let table = create("table");
let tbody = create("tbody");
let td = create("td");
let textarea = create("textarea");
let tfoot = create("tfoot");
let th = create("th");
let thead = create("thead");
let time = create("time");
let title = create("title");
let tr = create("tr");
let track = create("track");
let u = create("u");
let ul = create("ul");
let var = create("var");
let video = create("video");
let wbr = create("wbr");
let circle = create("circle");
let clipPath = create("clipPath");
let defs = create("defs");
let ellipse = create("ellipse");
let g = create("g");
let image = create("image");
let line = create("line");
let linearGradient = create("linearGradient");
let mask = create("mask");
let path = create("path");
let pattern = create("pattern");
let polygon = create("polygon");
let polyline = create("polyline");
let radialGradient = create("radialGradient");
let rect = create("rect");
let stop = create("stop");
let svg = create("svg");
let text = create("text");
let tspan = create("tspan");

/* Render plain text */
external str : string => t = "%identity";

/* Extract children from reason props */
module ReactProps = {
  [@bs.deriving abstract]
  type props = {children: t};
  external fromProps : 'a => props = "%identity";
};
let extractChildren = props =>
  props |> ReactProps.fromProps |> ReactProps.childrenGet;
