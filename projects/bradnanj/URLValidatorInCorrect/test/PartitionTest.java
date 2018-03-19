import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class PartitionTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}


	@Test
	public void partition1() {
		UrlValidator url = new UrlValidator();
		assertTrue("First Partition", url.isValid("http://www.google.com/test1?action=view"));
	
	}
	
	@Test
	public void partition2() {
		UrlValidator url = new UrlValidator();
		assertTrue("Second Partition", url.isValid(null));
	
	}
	
	@Test
	public void partition3() {
		UrlValidator url = new UrlValidator();
		assertTrue("Third Partition", url.isValid("ftp://255.255.255.255/test1/test?action=edit&mode=up"));
	
	}
}
