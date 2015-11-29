package qt4java;

public class QApplication extends QObject {
	public QApplication( String args[] ) {
		super( create( args ));
	}

	public native int exec();

	private static native long create( String args[] );
}
