package ceng.ceng351.musicdb;

import ceng.ceng351.musicdb.QueryResult.ArtistNameNumberOfSongsResult;
import ceng.ceng351.musicdb.QueryResult.ArtistNameSongNameGenreRatingResult;
import ceng.ceng351.musicdb.QueryResult.TitleReleaseDateRatingResult;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//replace("\'","''") ekle tum stringlere
// tab delimited yapmıyorum. 
// on delete cascade de yapmıyorum
/**
 *
 * @author Asus
 */
public class MUSICDB implements IMUSICDB{
	
    private static String user = "e2171353";//"pa1_user";  
    private static String password = "4ee8115f"; //"123456";
    private static String host = "144.122.71.57"; //"localhost";
    private static String database = "db2171353";//"pa1_recitation";
    private static int port = 8084; // 3306;
 /*
    private static String user = "root";//"pa1_user";  
    private static String password = "root"; //"123456";
    private static String host = "127.0.0.1"; //"localhost";
    private static String database = "pa1_recitation";//"pa1_recitation";
    private static int port = 3306; // 3306;    
  */
    private Connection con;

    public MUSICDB() {
        // TODO Auto-generated constructor stub
    }

    @Override
    public void initialize() {
        String url = "jdbc:mysql://" + this.host + ":" + this.port + "/" + this.database ;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            this.con =  DriverManager.getConnection(url, this.user, this.password);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        } 
    }
	
    @Override
    public int dropTables() {

        int result;
        int numberofTablesDropped = 0;

        
        String queryDropListenTable = "drop table if exists listen";
        try {
            Statement statement = this.con.createStatement();

            result = statement.executeUpdate(queryDropListenTable);
            numberofTablesDropped++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        String queryDropUserTable = "drop table if exists user";


        try {
            Statement statement = this.con.createStatement();

            result = statement.executeUpdate(queryDropUserTable);
            numberofTablesDropped++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
                String queryDropSongTable = "drop table if exists song";
        try {
            Statement statement = this.con.createStatement();

            //Team Player
            result = statement.executeUpdate(queryDropSongTable);
            numberofTablesDropped++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        
                
        String queryDropAlbumTable = "drop table if exists album";
        try {
            Statement statement = this.con.createStatement();

            //Team Player
            result = statement.executeUpdate(queryDropAlbumTable);
            numberofTablesDropped++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        String queryDropArtistTable = "drop table if exists artist";


        try {
            Statement statement = this.con.createStatement();

            //Team Player
            result = statement.executeUpdate(queryDropArtistTable);
            numberofTablesDropped++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
   
        return numberofTablesDropped;
    }
    

    @Override
    public int createTables() {

        int result;
        int numberofTablesInserted = 0;
       

        String queryCreateUserTable = "create table user (" 
                                                            +   "userid int," + 
                                                                "username varchar(60)," + 
                                                                "email varchar(30)," +
                                                                "password varchar(30),"  + "primary key (userid))";
        
        
        
        try {
            Statement statement = this.con.createStatement();

            //Player Table
            result = statement.executeUpdate(queryCreateUserTable);
            System.out.println(result);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        
        String queryCreateArtistTable = "create table artist (" 
                                                            +   "artistid int," + 
                                                                "artistname varchar(60), " +
                                                                "primary key (artistid))" ;
        
        
        try {
            Statement statement = this.con.createStatement();

            //Player Table
            result = statement.executeUpdate(queryCreateArtistTable);
            System.out.println(result);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //album(albumID:int, title:varchar(60), albumGenre:varchar(30), albumRating:double, releaseDate:date, artistID:int)
        String queryCreateAlbumTable = "create table album (" 
                                                            +   "albumid int," + 
                                                                "title varchar(60)," + 
                                                                "albumgenre varchar(30)," +
                                                                "albumrating double," +
                                                                "releasedate date," +
                                                                "artistid int,"  +
                                                                "primary key (albumid)," +
                                                                "foreign key(artistid) references artist(artistid) on delete cascade ON UPDATE cascade)"   ;
                                                                    //on delete cascade falan eklemen gerekebilir
                                                                    
                                                                    
        try {
            Statement statement = this.con.createStatement();

            //Player Table
            result = statement.executeUpdate(queryCreateAlbumTable);
            System.out.println(result);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        //song(songID:int, songName:varchar(60), genre:varchar(30), rating:double, artistID:int, albumID:int)
        String queryCreateSongTable = "create table song (" 
                                                            +   "songid int," + 
                                                                "songname varchar(60)," + 
                                                                "genre varchar(30)," +
                                                                "rating double," +
                                                                "artistid int," +
                                                                "albumid int,"  +
                                                                "primary key (songid)," +
                                                                "foreign key(artistid) references artist(artistid) on delete cascade ON UPDATE cascade," +  
                                                                "foreign key(albumid) references album(albumid) on delete cascade ON UPDATE cascade) "  ;



                                                                    //on delete cascade falan eklemen gerekebilir
        try {
            Statement statement = this.con.createStatement();

            //SONG Table
            result = statement.executeUpdate(queryCreateSongTable);
            System.out.println(result);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //listen(userID:int, songID:int, lastListenTime:timestamp, listenCount:int)
            String queryCreateListenTable = "create table listen (" 
                                                            +   "userid int," + 
                                                                "songid int," + 
                                                                "lastListenTime timestamp," +
                                                                "listencount int," +
                                                                "primary key (userid,songid)," +
                                                                "foreign key(userid) references user(userid) on delete cascade ON UPDATE cascade," +  
                                                                "foreign key(songid) references song(songid) on delete cascade ON UPDATE cascade)"  ;
                                                                    //on delete cascade falan eklemen gerekebilir
        try {
            Statement statement = this.con.createStatement();

            //Player Table
            result = statement.executeUpdate(queryCreateListenTable);
            System.out.println(result);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return numberofTablesInserted;
    }

    @Override
    
    
    //album(albumID:int, title:varchar(60), albumGenre:varchar(30), albumRating:double, releaseDate:date, artistID:int)
    public int insertAlbum(Album[] albums) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        int result = 0;
        int noofalbuminserted = 0;
        //new Player(11, "Barcelona", "Neymar", 22, "LWF"),
        String query;
        for (int i = 0; i < albums.length; i++) {
          query = "insert into album values ('" + 
                albums[i].getAlbumID()+ "','" +
                albums[i].getTitle().replace("\'","''") + "','" +
                albums[i].getAlbumGenre() + "','" +
                albums[i].getAlbumRating() + "','"+
                albums[i].getReleaseDate() + "','"+
                albums[i].getArtistID() +"')" ;
        
        try {
            Statement st = this.con.createStatement();
            result = st.executeUpdate(query);
            System.out.println(result);

            //Close
            st.close();
            noofalbuminserted++;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        }
        return noofalbuminserted;
    }

    @Override
    public int insertArtist(Artist[] artists) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        int noofartistinserted = 0;
        String query;
        for (int i = 0; i < artists.length; i++) {
          query = "insert into artist values ('" + 
                artists[i].getArtistID()+ "','" +
                artists[i].getArtistName().replace("\'","''") + "')" ;
        
        try {
            Statement st = this.con.createStatement();
              int result = st.executeUpdate(query);
            System.out.println(result);

            //Close
            st.close();
            noofartistinserted++;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        }
        return noofartistinserted;
    }

    
    
    @Override
    //song(songID:int, songName:varchar(60), genre:varchar(30), rating:double, artistID:int, albumID:int)
    public int insertSong(Song[] songs) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        int noofsonginserted = 0;
        String query;
        for (int i = 0; i < songs.length; i++) {
          query = "insert into song values ('" + 
                songs[i].getSongID()+ "','" +
                songs[i].getSongName().replace("\'","''") + "','" +
                songs[i].getGenre() + "','" +
                songs[i].getRating() + "','"+
                songs[i].getArtistID() + "','"+
                songs[i].getAlbumID() +"')" ;
        
        try {
            Statement st = this.con.createStatement();
              int result = st.executeUpdate(query);
            System.out.println(result);

            //Close
            st.close();
            noofsonginserted++;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        }
        return noofsonginserted;
    }

    @Override
    public int insertUser(User[] users) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        int result = 0;
        int noofuserinserted = 0;
        String query;
        for (int i = 0; i < users.length; i++) {
          query = "insert into user values ('" + 
                users[i].getUserID()+ "','" +
                users[i].getUserName().replace("\'","''") + "','" +
                users[i].getEmail() + "','" +
                users[i].getPassword().replace("\'","''") + "')" ;
        
        try {
            Statement st = this.con.createStatement();
            result = st.executeUpdate(query);
            System.out.println(result);

            //Close
            st.close();
            noofuserinserted++;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        }
        return noofuserinserted;
    }

    

    @Override
    //listen(userID:int, songID:int, lastListenTime:timestamp, listenCount:int)
    public int insertListen(Listen[] listens) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        int nooflisteninserted = 0;
        String query;
        for (int i = 0; i < listens.length; i++) {
          query = "insert into listen values ('" + 
                listens[i].getUserID()+ "','" +
                listens[i].getSongID() + "','" +
                listens[i].getLastListenTime() + "','" +
                listens[i].getListenCount() + "')" ;
        
        try {
            Statement st = this.con.createStatement();
              int result = st.executeUpdate(query);
            System.out.println(result);

            //Close
            st.close();
            nooflisteninserted++;

        } catch (SQLException e) {
            e.printStackTrace();
        }
        }
        return nooflisteninserted;
    }

    @Override
    public QueryResult.ArtistNameSongNameGenreRatingResult[] getHighestRatedSongs() {
            ResultSet rs;

	    List<ArtistNameSongNameGenreRatingResult>  ansngrList = new ArrayList<ArtistNameSongNameGenreRatingResult>();

	    String query = "select a.artistname, s.songname, s.genre, s.rating from song s inner join artist a on a.artistid=s.artistid "+  
		"where s.rating >= (select max(s1.rating) from song s1) order by a.artistname asc";

            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);

		while(rs.next()){
			ArtistNameSongNameGenreRatingResult ansngr = null;

			String artistName = rs.getString("artistname");
			String songName = rs.getString("songname");
			String genre = rs.getString("genre");
                        double rating = rs.getDouble("rating");

			ansngr = new ArtistNameSongNameGenreRatingResult(artistName, songName, genre, rating);
			ansngrList.add(ansngr);
		}

            }catch (SQLException e) {
                e.printStackTrace();

    }
            	ArtistNameSongNameGenreRatingResult[] ansngrArray = new ArtistNameSongNameGenreRatingResult[ansngrList.size()];
		ansngrArray = ansngrList.toArray(ansngrArray);
		System.out.println(ansngrList.get(0));
                // tab delimited yap
                return ansngrArray;
    }

    @Override
    public QueryResult.TitleReleaseDateRatingResult getMostRecentAlbum(String artistName) {
            ResultSet rs;

	    List<TitleReleaseDateRatingResult>  trdrList = new ArrayList<TitleReleaseDateRatingResult>();

	    String query = "select a.title, a.releasedate, a.albumrating " +
                            "from album a inner join artist s on a.artistID=s.artistID " +  
		"where s.artistname = '"+ artistName+ "' and a.releasedate >= (select max(a1.releasedate) from album a1)";

            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);

		rs.next();
			TitleReleaseDateRatingResult trdr = null;

			String title = rs.getString("title");
			String releasedate = rs.getString("releasedate");
			double albumrating = rs.getDouble("albumrating");
                        

			trdr = new TitleReleaseDateRatingResult(title, releasedate, albumrating);
			trdrList.add(trdr);
		

            }catch (SQLException e) {
                e.printStackTrace();

    }

		System.out.println(trdrList.get(0));
                // tab delimited yap
                return trdrList.get(0);
        
    }

    @Override
    public QueryResult.ArtistNameSongNameGenreRatingResult[] getCommonSongs(String userName1, String userName2) {
      
        
        
        
        
        
        
        
             ResultSet rs;

	    List<ArtistNameSongNameGenreRatingResult>  ansngrList = new ArrayList<ArtistNameSongNameGenreRatingResult>();

	    String query = "select a.artistname, s.songname, s.genre, s.rating " +
                        "from  song s, artist a " +
                        "where a.artistid = s.artistid and s.songid in ( " +
                        "select l.songid " +
                        "from listen l, user u " +
                        "where u.username =\""+ userName1 +"\" and u.userid = l.userid " +
                        "and l.songid in " +
                        "(select l1.songid from user u1 ,listen l1 where u1.username=\""+ userName2 +"\" and u1.userid = l1.userid )) order by s.rating desc ";
                            
                           
            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);

		while(rs.next()){
			ArtistNameSongNameGenreRatingResult ansngr = null;

			String artistName = rs.getString("artistname");
			String songName = rs.getString("songname");
			String genre = rs.getString("genre");
                        double rating = rs.getDouble("rating");

			ansngr = new ArtistNameSongNameGenreRatingResult(artistName, songName, genre, rating);
			ansngrList.add(ansngr);
		}

            }catch (SQLException e) {
                e.printStackTrace();

    }
            	ArtistNameSongNameGenreRatingResult[] ansngrArray = new ArtistNameSongNameGenreRatingResult[ansngrList.size()];
		ansngrArray = ansngrList.toArray(ansngrArray);
		System.out.println(ansngrList.get(0));

                // tab delimited yap
                return ansngrArray;

    
        
    }

    
    
    
    
    
    @Override
    public QueryResult.ArtistNameNumberOfSongsResult[] getNumberOfTimesSongsListenedByUser(String userName) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
            ResultSet rs;

	    List<ArtistNameNumberOfSongsResult>  annosList = new ArrayList<>();

	    String query = "select a.artistname, sum(l.listencount) " +
                            "from artist a, listen l, user u, song s " +
                                "where u.username = \"" + userName + "\" and l.userid = u.userid and a.artistid = s.artistid and l.songid = s.songid group by a.artistname";
                     
            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);

		while(rs.next()){
			ArtistNameNumberOfSongsResult annos = null;

			String artistName = rs.getString("a.artistname");
                        int numberofsongs = rs.getInt("sum(l.listencount)");
                        
			annos = new ArtistNameNumberOfSongsResult(artistName, numberofsongs);
			annosList.add(annos);
		}

            }
            catch (SQLException e) {
                e.printStackTrace();

            }

            	ArtistNameNumberOfSongsResult[] annosArray = new ArtistNameNumberOfSongsResult[annosList.size()];
		annosArray = annosList.toArray(annosArray);
            
		System.out.println(annosArray[0].artistName);

                // tab delimited yap
                return annosArray;        
    }

    @Override
    public User[] getUsersWhoListenedAllSongs(String artistName) {
            ResultSet rs;

	    List<User>  guwlasList = new ArrayList<>();

	    String query = "select u.userid, u.username, u.email, u.password from user u " +
                            "where not exists (select s.songid " +
                            "from song s ,artist a " +
                            "where a.artistname = \'" + artistName + "\' and s.artistid = a.artistid and not exists (select l.songid " +
                            "from listen l " +
                            "where l.songid = s.songid " +
                            "and l.userid = u.userid))";
                     
            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);
                
                

		while(rs.next()){
			User guwlas = null;

			int userID = rs.getInt("userid");
                        
                        String username = rs.getString("username");	
                        String email = rs.getString("email");	
                        String passwordd = rs.getString("password");	
                        guwlas = new User(userID,username,email,passwordd);
			guwlasList.add(guwlas);
		}

            }
            catch (SQLException e) {
                e.printStackTrace();

            }

            	User[] guwlasArray = new User[guwlasList.size()];
		guwlasArray = guwlasList.toArray(guwlasArray);
                // tab delimited yap
                return guwlasArray;   

    }

    @Override
    public QueryResult.UserIdUserNameNumberOfSongsResult[] getUserIDUserNameNumberOfSongsNotListenedByAnyone() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Artist[] getArtistSingingPopGreaterAverageRating(double rating) {
            ResultSet rs;

	    List<Artist>  gaspList = new ArrayList<Artist>();

	    String query = "select distinct a.artistid, a.artistname from artist a, song s "
                    + "where s.genre =\'Pop\' and a.artistid = s.artistid and a.artistid "
                    + "in(select a.artistid from song s1 where s1.artistid = a.artistid group by a.artistid having avg(s1.rating) >" + rating + ")";
                     
            try {

		Statement st  = this.con.createStatement();
		rs = st.executeQuery(query);

		while(rs.next()){
			Artist gasp = null;

			int artistID = rs.getInt("artistid");
                        
                        String artistname = rs.getString("artistname")	;	
                        gasp = new Artist(artistID,artistname);
			gaspList.add(gasp);
		}

            }
            catch (SQLException e) {
                e.printStackTrace();

            }

            	Artist[] gaspArray = new Artist[gaspList.size()];
		gaspArray = gaspList.toArray(gaspArray);
                // tab delimited yap
                return gaspArray;   

    }


    @Override
    public Song[] retrieveLowestRatedAndLeastNumberOfListenedSongs() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
    
    @Override
    public int multiplyRatingOfAlbum(String releaseDate) {
        int result = 0;
        String query ="update album a set a.albumrating = a.albumrating*(3/2) where a.releasedate > \""+ releaseDate+ "\"";
        try {
            Statement st  = this.con.createStatement();
            result = st.executeUpdate(query);
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return result;
    }

    @Override
    public Song deleteSong(String songName) {

        ResultSet rs;
        Song song  = null;

        String query = "select * from song where songname =\"" +  songName + "\";";

        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            Statement st1  = this.con.createStatement();

            String query1 = "delete from song where songname=\"" + songName + "\"" ;
            st1.executeUpdate(query1);

            rs.next();

            int songID = rs.getInt("songid");
                        
            String songname = rs.getString("songname");	
            String genre = rs.getString("genre");	
            double rating = rs.getDouble("rating");	
            int artistID = rs.getInt("artistid");
            int albumID = rs.getInt("albumid");

            song = new Song(songID,songname,genre,rating, artistID, albumID);

            //Close
            st.close();
            st1.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
       
  
        return song;
        

    
    }

    

}

