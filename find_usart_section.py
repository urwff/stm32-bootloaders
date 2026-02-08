import sys
from pypdf import PdfReader

def list_bookmarks(bookmarks, indent=0):
    for item in bookmarks:
        if isinstance(item, list):
            list_bookmarks(item, indent + 1)
        else:
            title = item.title
            if "USART" in title:
                print(f"{'  ' * indent}Title: {title}, Page: {reader.get_destination_page_number(item) + 1}")

try:
    reader = PdfReader(r"doc\1-STM32F10x-英文参考手册_最新.pdf")
    print(f"Total pages: {len(reader.pages)}")
    
    # Try getting the outline/bookmarks
    if reader.outline:
        print("Searching bookmarks for USART...")
        list_bookmarks(reader.outline)
    else:
        print("No bookmarks found.")

except Exception as e:
    print(f"Error: {e}")
