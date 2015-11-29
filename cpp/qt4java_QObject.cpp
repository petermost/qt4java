#include "qt4java.hpp"
#include <QObject>


extern "C" JNIEXPORT jlong JNICALL Java_qt4java_QObject_create( JNIEnv *env, jclass, jobject parent )
{
	qDebug( Q_FUNC_INFO );

	QObject *parentObject = getPointer< QObject >( env, parent );
	QObject *object = new QObject( parentObject );

	return reinterpret_cast< jlong >( object );
}


extern "C" JNIEXPORT void JNICALL Java_qt4java_QObject_destroy(JNIEnv *, jclass, jlong pointer )
{
	qDebug( Q_FUNC_INFO );

	QObject *object = reinterpret_cast< QObject * >( pointer );
	delete object;
}

