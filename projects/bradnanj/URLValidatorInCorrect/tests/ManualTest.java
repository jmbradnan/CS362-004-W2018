import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class ManualTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testIsValid() {
		UrlValidator url = new UrlValidator();
		assertTrue("Valid Input Failed", url.isValid("http://www.google.com"));
	
	}
	
	@Test
	public void testIsValid2() {
		UrlValidator url = new UrlValidator();
		assertTrue("Invalid Input Failed", url.isValid("://www.google.com"));
	
	}
	
	@Test
	public void testIsValid3() {
		UrlValidator url = new UrlValidator();
		assertTrue("Valid Input Failed", url.isValid("ftp://go.com"));
	
	}
	
	@Test
	public void testIsValid4() {
		UrlValidator url = new UrlValidator();
		assertTrue("Invalid Input Failed", url.isValid("http:/1.2.3:-1"));
	
	}
}
