#include "qt4java.hpp"
#include <QPushButton>
#include <QString>

class QJPushButton : public QPushButton {
	public:
		QJPushButton( const QString &text, QWidget *parent = 0 )
			: QPushButton( text, parent )
		{
		}
};

extern "C" JNIEXPORT jlong JNICALL Java_qt4java_QPushButton_create( JNIEnv *env, jclass, jstring text, jobject parent )
{
	qDebug( Q_FUNC_INFO );

	QString buttonText = convertJStringToQString( env, text );
	QWidget *parentWidget = getPointer< QWidget >( env, parent );
	QPushButton *button = new QJPushButton( buttonText, parentWidget );
	return reinterpret_cast< jlong >( button );
}

