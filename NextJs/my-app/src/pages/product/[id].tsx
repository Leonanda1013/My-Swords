import { useRouter } from "next/router";

export default function DetailProduct() {
  const { query } = useRouter();

  return (
    <div>
      <p>This is a detail product page.</p>
      <p>Product ID: {query.id}</p>
    </div>
  );
}
