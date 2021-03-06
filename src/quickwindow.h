#ifndef BRIG_QUICKWINDOW_WRAP_H
#define BRIG_QUICKWINDOW_WRAP_H

#include <node.h>
#include <QQuickWindow>
#include "brig.h"

namespace Brig {

	using namespace v8;
	using namespace node;

	class QuickWindowWrap : public ObjectWrap {

		public:
			QuickWindowWrap();
			QuickWindowWrap(Handle<Value> qobject);
			~QuickWindowWrap();

			static Persistent<Function> constructor;
			static void Initialize(Handle<Object> target);
			static Handle<Value> NewInstance(QObject *);
			static Handle<Value> NewInstance(Handle<Value>);

			QQuickWindow *GetObject() const { return obj; };

		private:

			static Handle<Value> New(const Arguments& args);

			/* Methods */
			static Handle<Value> show(const Arguments& args);
			static Handle<Value> toObject(const Arguments& args);

			Handle<Value> prototype_object;
			QQuickWindow *obj;
	};

}

#endif
