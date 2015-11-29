#include "qt4java.hpp"
#include <QString>

// For debugging use: gdbtui --args java -Djava.library.path=./cpp/build/Debug/ -jar helloqt.jar

const char POINTER_FIELD_NAME[] = "pointer";
const char POINTER_FIELD_SIGNATURE[] = "J";

jclass getObjectClass( JNIEnv *env, jobject object )
{
	jclass objectClass = env->GetObjectClass( object );
	Q_ASSERT( objectClass != nullptr );
	return objectClass;
}

jfieldID getFieldID( JNIEnv *env, jclass fieldClass, const char fieldName[], const char fieldSignature[] )
{
	jfieldID fieldID = env->GetFieldID( fieldClass, fieldName, fieldSignature );
	Q_ASSERT( fieldID != nullptr );
	return fieldID;
}

jlong getLongField( JNIEnv *env, jobject object, jfieldID fieldID )
{
	jlong fieldValue = env->GetLongField( object, fieldID );
	Q_ASSERT( !env->ExceptionCheck() );
	return fieldValue;
}

void setLongField( JNIEnv *env, jobject object, jfieldID fieldID, jlong fieldValue )
{
	env->SetLongField( object, fieldID, fieldValue );
	Q_ASSERT( !env->ExceptionCheck() );
}

int getStringUtfLength( JNIEnv *env, jstring jstr )
{
	jsize length = env->GetStringUTFLength( jstr );
	Q_ASSERT( !env->ExceptionCheck() );
	return length;
}

const char *getStringUtfChars( JNIEnv *env, jstring jstr )
{
	const char *cstr = env->GetStringUTFChars( jstr, nullptr );
	Q_ASSERT( cstr != nullptr );
	return cstr;
}

void releaseStringUtfChars( JNIEnv *env, jstring jstr, const char *cstr )
{
	env->ReleaseStringUTFChars( jstr, cstr );
	Q_ASSERT( !env->ExceptionCheck() );
}

QString convertJStringToQString( JNIEnv *env, jstring jstr )
{
	const char *cstr = getStringUtfChars( env, jstr );
	jsize cstrLength = getStringUtfLength( env, jstr );
	QString qstr = QString::fromUtf8( cstr, cstrLength );
	releaseStringUtfChars( env, jstr, cstr );

	return qstr;
}
