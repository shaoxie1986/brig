"use strict";

var Brig = require('../../');

var brig = new Brig();

// Create Engine
var engine = new brig.QmlEngine();
var rootContext = engine.rootContext();
var context = new brig.QmlContext(rootContext);

// Loading QML file
var component = new brig.QmlComponent(engine, 'application.qml');
var item = component.create(context);

// Invoke
var result = item.invokeMethod('hello', 1, 2);
console.log(result);
