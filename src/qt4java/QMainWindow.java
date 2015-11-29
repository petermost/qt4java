package qt4java;

public class QMainWindow extends QWidget {

	public QMainWindow( QWidget parent, int windowFlags ) {
		super( 	create( parent, windowFlags ));
	}

	protected QMainWindow( long pointer ) {
		super( pointer );
	}

	private static native long create( QObject parent, int windowFlags );
}
