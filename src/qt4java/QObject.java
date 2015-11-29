package qt4java;

public class QObject implements AutoCloseable {

	public QObject( QObject parent ) {
		create( parent );
	}

	protected QObject( long pointer ) {
		this.pointer = pointer;
	}

	@Override
	public void close() throws Exception {
		destroy( pointer );
	}

	private static native long create( QObject parent );

	private static native void destroy( long pointer );

	private long pointer;
}
