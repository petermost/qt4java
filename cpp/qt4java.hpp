#ifndef QT4JAVA_HPP
#define QT4JAVA_HPP

#include <QtCore/qglobal.h>
#include <jni.h>

#if defined( QT4JAVA_LIBRARY )
	#define QT4JAVA_EXPORT Q_DECL_EXPORT
#else
	#define QT4JAVA_EXPORT Q_DECL_IMPORT
#endif

QT4JAVA_EXPORT extern const char POINTER_FIELD_NAME[];
QT4JAVA_EXPORT extern const char POINTER_FIELD_SIGNATURE[];

QT4JAVA_EXPORT jclass getObjectClass( JNIEnv *env, jobject object );
QT4JAVA_EXPORT jfieldID getFieldID( JNIEnv *env, jclass fieldClass, const char fieldName[], const char fieldSignature[] );
QT4JAVA_EXPORT jlong getLongField( JNIEnv *env, jobject object, jfieldID fieldID );
QT4JAVA_EXPORT void setLongField( JNIEnv *env, jobject object, jfieldID fieldID, jlong fieldValue );
QT4JAVA_EXPORT QString convertJStringToQString( JNIEnv *env, jstring jstr );

template < typename T >
	T *getPointer( JNIEnv *env, jobject object )
	{
		Q_STATIC_ASSERT( sizeof( jlong ) >= sizeof( T * ));

		T *pointer = nullptr;
		if ( object != nullptr ) {
			jclass objectClass = getObjectClass( env, object );
			jfieldID pointerFieldID = getFieldID( env, objectClass, POINTER_FIELD_NAME, POINTER_FIELD_SIGNATURE );
			jlong pointerValue = getLongField( env, object, pointerFieldID );
			pointer = reinterpret_cast< T * >( pointerValue );
		}
		return pointer;
	}

template < typename T >
	void setPointer( JNIEnv *env, jobject object, T *pointer )
	{
		Q_STATIC_ASSERT( sizeof( jlong ) >= sizeof( T * ));

		jclass objectClass = getObjectClass( env, object );
		jfieldID pointerFieldID = getFieldID( env, objectClass, POINTER_FIELD_NAME, POINTER_FIELD_SIGNATURE );
		Q_ASSERT( pointer != nullptr );
		env->SetLongField( object, pointerFieldID, reinterpret_cast< jlong >( pointer ));
	}

#endif // QT4JAVA_HPP
