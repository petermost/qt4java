package qt4java;

public class QWidget extends QObject {

	public QWidget( QWidget parent, int windowFlags ) {
		super( create( parent, windowFlags ));
	}

	protected QWidget( long pointer ) {
		super( pointer );
	}
	private static native long create( QWidget parent, int windowFlags );

	public native void show();
}
