import csv
import requests
from bs4 import BeautifulSoup

class ProductScraper:
    def __init__(self, url):
        self.url = url

    def fetch_page(self):
        response = requests.get(self.url)
        if response.status_code == 200:
            return response.content
        else:
            raise Exception("Failed to fetch the page.")

    def scrape_products(self):
        page_content = self.fetch_page()
        soup = BeautifulSoup(page_content, "html.parser")
        
        products = []
        product_elements = soup.find_all("div", class_="product-item")
        
        for product_element in product_elements:
            name = product_element.find("h2").text.strip()
            price = product_element.find("span", class_="price").text.strip()
            products.append({"name": name, "price": price})
        
        return products

    def save_to_csv(self, data, filename):
        with open(filename, "w", newline="", encoding="utf-8") as csvfile:
            fieldnames = ["name", "price"]
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(data)


def main():
 website_url = "https://www.earthdata.nasa.gov/engage/open-data-services-and-software/api"
 scraper = ProductScraper(website_url)
 products_data = scraper.scrape_products()
 scraper.save_to_csv(products_data, "products.csv")            

if __name__ == "__main__":
    main()
   
