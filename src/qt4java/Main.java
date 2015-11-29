package qt4java;

public class Main {
	static {
		System.loadLibrary( "qt4java" );
	}
	public static void main( String[] args ) throws Exception {
		try ( QApplication application = new QApplication( args )) {
			try ( QPushButton button = new QPushButton( "Knopf", null )) {
				button.clicked.connect(( checked ) -> { System.out.println( "Knopf gedruckt" ); });
				button.show();
				application.exec();
			}
		}
	}

}
