package qt4java;

import qt4java.signal.*;

public class QPushButton extends QWidget {

	public final Signal1< Boolean > clicked = new Signal1<>();

	public QPushButton( String text, QWidget parent ) {
		super( create( text, parent ));
	}

	public QPushButton( long pointer ) {
		super( pointer );
	}

	public final void click() throws Exception {
		clicked.emit( false );
	}
	private static native long create( String text, QWidget parent );
}
