import requests

def check_status(url):

    # adding http if missing
    if not url.startswith("http://") and not url.startswith("https://"):
        url = "http://" + url

    try:
        print("\nChecking website...\n")

        response = requests.get(url, timeout=3)
        
        print(f"URL: {url}")
        print(f"Status Code: {response.status_code}")

        if response.status_code == 200:
            print("Status: Website is UP")
        else:
            print("Status: Website has an issue")

    except requests.exceptions.Timeout:
        print("Error:  Request Timeout")

    except requests.exceptions.ConnectionError:
        print("Error: Connection Failed")

    except requests.exceptions.RequestException as e:
        print("Error:", e)



target_url = input("Enter a website URL: ")
check_status(target_url)
