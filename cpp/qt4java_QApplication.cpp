#include "qt4java.hpp"
#include <QApplication>


extern "C" JNIEXPORT jlong JNICALL Java_qt4java_QApplication_create(JNIEnv *, jclass, jobjectArray arguments )
{
	qDebug( Q_FUNC_INFO );

	int argc = 0;
	char *argv[ argc ];

	QApplication *application = new QApplication( argc, argv );
	return reinterpret_cast< jlong >( application );
}


extern "C" JNIEXPORT jint JNICALL Java_qt4java_QApplication_exec( JNIEnv *env, jobject object )
{
	qDebug( Q_FUNC_INFO );

	QApplication *application = getPointer< QApplication >( env, object );
	return application->exec();
}
