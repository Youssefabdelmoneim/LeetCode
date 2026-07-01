class FoodRatings
{
public:
  int n;
  unordered_map<string, set<pair<int, string>>> cuisineToFood;
  unordered_map<string, string> foodCuisine;
  unordered_map<string, int> foodRating;

  FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
  {
    // O (n log n )
    n = foods.size();
    for (int i = 0; i < n; i++)
    {
      cuisineToFood[cuisines[i]].insert({-ratings[i], foods[i]}); // log ( n )
      foodCuisine[foods[i]] = cuisines[i];
      foodRating[foods[i]] = ratings[i];
    }
  }

  void changeRating(string food, int newRating)
  {

    string cuisine = foodCuisine[food];
    int oldRating = foodRating[food];
    foodRating[food] = newRating;
    cuisineToFood[cuisine].erase({-oldRating, food});  // o log ( n )
    cuisineToFood[cuisine].insert({-newRating, food}); // o log ( n )
  }

  string highestRated(string cuisine)
  {
    return cuisineToFood[cuisine].begin()->second;  // o ( 1 )
  }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */