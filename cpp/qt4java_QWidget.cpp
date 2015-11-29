#include "qt4java.hpp"
#include <QWidget>


extern "C" JNIEXPORT jlong JNICALL Java_qt4java_QWidget_create(JNIEnv *env, jclass, jobject parent, jint windowFlags )
{
	qDebug( Q_FUNC_INFO );

	QWidget *parentWidget = getPointer< QWidget >( env, parent );
	QWidget *widget = new QWidget( parentWidget, 0 );

	return reinterpret_cast< jlong >( widget );
}


extern "C" JNIEXPORT void JNICALL Java_qt4java_QWidget_show( JNIEnv *env, jobject object )
{
	qDebug( Q_FUNC_INFO );

	QWidget *widget = getPointer< QWidget >( env, object );
	widget->show();
}
