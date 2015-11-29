#include "qt4java.hpp"
#include <QMainWindow>


extern "C" JNIEXPORT jlong JNICALL Java_qt4java_QMainWindow_create( JNIEnv *env, jclass, jobject parent, jint windowFlags )
{
	qDebug( Q_FUNC_INFO );

	QWidget *parentWidget = getPointer< QWidget >( env, parent );
	QMainWindow *mainWindow = new QMainWindow( parentWidget );

	return reinterpret_cast< jlong >( mainWindow );
}
