package hw3;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Comparator;
import java.nio.file.Files;
import java.util.stream.Stream;
import java.io.IOException;
import java.text.DecimalFormat;
import java.lang.String;


public class Covid
{
  // You can add your own variables between them.
    public static <T> Predicate<T> distinctByKey(Function<? super T, Object> keyExtractor) 
    {
        Map<Object, Boolean> map = new ConcurrentHashMap<>();
        return t -> map.putIfAbsent(keyExtractor.apply(t), Boolean.TRUE) == null;
    } 
  // You can add your own variables between them.

  // You must not change between them.
  private List<List<String>> rows;

  public Covid()
  {
    try
    {
      this.rows = Files
          .lines(Paths.get("covid19.csv"))
          .map(row -> Arrays.asList(row.split(",")))
          .collect(Collectors.toList());
    }
    catch (IOException e)
    {
      e.printStackTrace();    
    }
  }
  // You must not change between them.

  public void printOnlyCases(String location, String date)
  {
    rows.stream().filter(l -> l.get(1).equals(location) && l.get(2).equals(date)).forEach(result -> System.out.print("Result: " + result.get(3)));
  }

  public long getDateCount(String location)
  {
    long toReturn = rows.stream().filter(l-> l.get(1).equals(location)).count();
    return toReturn;
  }

  public int getCaseSum(String date)
  {
    int toReturn = rows.stream().filter(l->l.get(2).equals(date)).mapToInt(c -> Integer.parseInt(c.get(4))).sum();
    
    return toReturn;
  }

  public long getZeroRowsCount(String location)
  {
    long toReturn = rows.stream().filter(l-> l.get(1).equals(location) && l.get(3).equals("0")  && l.get(4).equals("0") && l.get(5).equals("0")  && l.get(6).equals("0")).count();

    return toReturn;
  }

  public double getAverageDeath(String location)
  {
    double toReturn = rows.stream().filter(l->l.get(1).equals(location)).mapToInt(c -> Integer.parseInt(c.get(6))).average().getAsDouble();
    toReturn = Double.parseDouble(new DecimalFormat("##.00").format(toReturn).replace(",","."));
    return toReturn;
  }

  public String getFirstDeathDayInFirstTenRows(String location)
  {
   String toReturn;
     Optional<List<String>> temp = rows.stream().filter(l -> l.get(1).equals(location)).limit(10).filter(l->Integer.parseInt(l.get(5)) > 0).findFirst();
     if(temp.isPresent()) {
       toReturn = temp.get().get(2);
     }
     else {
       toReturn = "Not Found";
     }
      
     return toReturn;
  }

  public String[] getDateCountOfAllLocations()
  {   
    //String[] toReturn = rows.stream()
    //    .collect(Collectors.groupingBy(l->l.get(0)))
    //    .entrySet().stream().map(l-> l.getKey() +": "+ getDateCount(l.getKey())).toArray(String[]::new);
    
  // Here is a slow solution without any map library:
  // String[] toReturn = rows.stream()
    //    .map(l-> l.get(0) +": "+ getDateCount(l.get(1))).distinct().toArray(String[]::new);
        
   // burada once her ulkeyi ayri ayri alsin. sonra
   String[] toReturn = rows.stream().filter(distinctByKey(l->l.get(0)))
          .map(l-> l.get(0) +": "+ getDateCount(l.get(1))).distinct().toArray(String[]::new);
        
    return toReturn;
  }

  public List<String> getLocationsFirstDeathDay()
  {
    List<String> toReturn = rows.stream().filter(l-> l.get(5).equals(l.get(6)) && Integer.parseInt(l.get(5)) > 0 )
        .map(l-> l.get(1) + ": " + l.get(2)).collect(Collectors.toList());

    return toReturn;
  }

  public String trimAndGetMax(String location, int trimCount)
  {
    List<String> toReturnList = rows.stream().filter(l-> l.get(1).equals(location))
          .sorted((l, c)-> Integer.parseInt(l.get(4))-Integer.parseInt(c.get(4)))
          .skip(trimCount).limit(getDateCount(location)-2*trimCount)
        .max((l, c)-> Integer.parseInt(l.get(6))-Integer.parseInt(c.get(6))).get();

    String toReturn = toReturnList.get(2) + ": " + toReturnList.get(6);
    return toReturn;
  }

  public List<List<String>> getOnlyCaseUpDays(String location)
  {  
    List<List<String>> toReturn = rows.stream().filter(l-> l.get(1).equals(location) && Integer.parseInt(l.get(4)) != 0 ).collect(Collectors.toList());

    long count = rows.stream().filter(l-> l.get(1).equals(location) && Integer.parseInt(l.get(4)) != 0 ).count();
    System.out.println("Result: "+ count);
    return toReturn;
  }
  
  public static void main(String[] args)
  {
    // You can test your function in here.
    // This part is not graded.
    String location = "Turkey";
    String date = "2020-04-05";
    Covid cov = new Covid();
    cov.printOnlyCases(location,date);
    
    System.out.println("\n");
    
    System.out.println(cov.getDateCount(location));
    
    System.out.println("\n");
    
    System.out.println(cov.getCaseSum(date));
    
    System.out.println("\n");
    
    System.out.println(cov.getZeroRowsCount(location));
    
    System.out.println("\n");
    
    System.out.println(cov.getAverageDeath(location));
    
    System.out.println("\n");
    
    System.out.println(cov.getFirstDeathDayInFirstTenRows(location));
    
    System.out.println("\n");
    
    System.out.println(Arrays.toString(cov.getDateCountOfAllLocations()));
    
    System.out.println("\n");
    
    System.out.println(cov.getLocationsFirstDeathDay());
    
    System.out.println("\n");
    
    System.out.println(cov.trimAndGetMax(location, 5));
    
    System.out.println("\n");
    
    System.out.println(cov.getOnlyCaseUpDays(location));
    
  }


}

